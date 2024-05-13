/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** display_db
*/

#include "db/db.h"

static void display_teams(db_t *db)
{
    printf("Teams:\n");
    for (size_t i = 0; db->teams[i] != NULL; i++) {
        printf("Team %ld:\n", i);
        printf("uuid: %s\n", db->teams[i]->uuid);
        printf("name: %s\n", db->teams[i]->name);
        printf("description: %s\n", db->teams[i]->description);
        printf("\n");
    }
}

static void display_users(db_t *db)
{
    printf("Users:\n");
    for (size_t i = 0; db->users[i] != NULL; i++) {
        printf("User %ld:\n", i);
        printf("uuid: %s\n", db->users[i]->uuid);
        printf("username: %s\n", db->users[i]->username);
        printf("context: %d\n", db->users[i]->context);
        printf("team_nb: %d\n", (int)get_len((void **)db->users[i]->teams));
        printf("\n");
    }
}

void display_db(void)
{
    db_t *db = get_set_db(NULL);

    if (db == NULL)
        return;
    if (db->users != NULL)
        display_users(db);
    if (db->teams != NULL)
        display_teams(db);
}
