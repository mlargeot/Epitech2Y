/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myusers-morgan.largeot
** File description:
** user
*/

#include "db/db.h"

int free_users(user_t **users)
{
    if (users == NULL)
        return 1;
    for (size_t i = 0; users[i] != NULL; i++) {
        safe_free(users[i]->uuid);
        safe_free(users[i]);
    }
    safe_free(users);
    return 0;
}

user_t **db_get_users(void)
{
    db_t *db = get_set_db(NULL);

    return db->users;
}

int db_new_user(char *username, char *password)
{
    db_t *db = get_set_db(NULL);
    user_t *new_user = malloc(sizeof(user_t));
    size_t len = get_len((void **)db->users);

    if (new_user == NULL)
        return 1;
    new_user->uuid = calloc(37, sizeof(char));
    new_user->username = strdup(username);
    new_user->password = strdup(password);
    new_user->context = UNDEFINED;
    new_user->teams = malloc(sizeof(team_t *) * 1);
    new_user->teams[0] = NULL;
    db->users = realloc(db->users, sizeof(user_t *) * (len + 2));
    db->users[len] = new_user;
    db->users[len + 1] = NULL;
    return 0;
}

static int save_user_teams(FILE *file, user_t *user)
{
    size_t len = get_len((void **)user->teams);

    fwrite(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++)
        fwrite_str(file, user->teams[i]->uuid);
    return 0;
}

int save_users(FILE *file, user_t **users)
{
    size_t len = get_len((void **)users);

    fwrite(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        fwrite_str(file, users[i]->uuid);
        fwrite_str(file, users[i]->username);
        fwrite_str(file, users[i]->password);
        save_user_teams(file, users[i]);
    }
    return 0;
}

static int load_user_teams(FILE *file, user_t *user)
{
    size_t len = 0;
    team_t *team = NULL;

    fread(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        team = db_get_team(fread_str(file));
        user->teams = realloc(user->teams, sizeof(team_t *) * (i + 2));
        user->teams[i] = team;
        user->teams[i + 1] = NULL;
    }
    return 0;
}

int load_users(FILE *file, db_t *db)
{
    size_t len = 0;
    user_t *new_user = NULL;

    fread(&len, sizeof(size_t), 1, file);
    printf("Loading %ld users\n", len);
    for (size_t i = 0; i < len; i++) {
        printf("Loading user %ld/%ld\n", i + 1, len);
        new_user = malloc(sizeof(user_t));
        if (new_user == NULL)
            return 1;
        new_user->uuid = fread_str(file);
        new_user->username = fread_str(file);
        new_user->password = fread_str(file);
        new_user->context = UNDEFINED;
        load_user_teams(file, new_user);
        db->users = realloc(db->users, sizeof(user_t *) * (i + 2));
        db->users[i] = new_user;
        db->users[i + 1] = NULL;
    }
    return 0;
}
