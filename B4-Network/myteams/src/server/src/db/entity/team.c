/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** team
*/

#include "db/db.h"

int free_teams(team_t **teams)
{
    if (teams == NULL)
        return 1;
    for (size_t i = 0; teams[i] != NULL; i++) {
        safe_free(teams[i]->uuid);
        safe_free(teams[i]->name);
        safe_free(teams[i]->description);
        safe_free(teams[i]);
    }
    safe_free(teams);
    return 0;
}

team_t **db_get_teams(void)
{
    db_t *db = get_set_db(NULL);

    return db->teams;
}

team_t *db_new_team(char *name, char *description)
{
    db_t *db = get_set_db(NULL);
    team_t *new_team = malloc(sizeof(team_t));
    size_t len = get_len((void **)db->teams);

    if (new_team == NULL)
        return NULL;
    new_team->uuid = uuid_gen(NULL);
    new_team->name = strdup(name);
    new_team->description = strdup(description);
    if (new_team->uuid == NULL || new_team->name == NULL
        || new_team->description == NULL)
        return NULL;
    db->teams = realloc(db->teams, sizeof(team_t *) * (len + 2));
    db->teams[len] = new_team;
    db->teams[len + 1] = NULL;
    return new_team;
}

int save_teams(FILE *file, team_t **teams)
{
    size_t len = get_len((void **)teams);

    fwrite(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        fwrite_str(file, teams[i]->uuid);
        fwrite_str(file, teams[i]->name);
        fwrite_str(file, teams[i]->description);
    }
    return 0;
}

int load_teams(FILE *file, db_t *db)
{
    size_t len = 0;
    team_t *new_team = NULL;

    fread(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        new_team = malloc(sizeof(team_t));
        if (new_team == NULL)
            return 1;
        new_team->uuid = fread_str(file);
        new_team->name = fread_str(file);
        new_team->description = fread_str(file);
        db->teams = realloc(db->teams, sizeof(team_t *) * (i + 2));
        db->teams[i] = new_team;
        db->teams[i + 1] = NULL;
    }
    return 0;
}
