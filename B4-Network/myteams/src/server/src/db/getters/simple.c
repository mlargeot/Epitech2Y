/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** simple
*/

#include "db/db.h"

team_t *db_get_team(char *uuid)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->teams[i] != NULL; i++) {
        if (strcmp(db->teams[i]->uuid, uuid) == 0)
            return db->teams[i];
    }
    return NULL;
}

channel_t *db_get_channel(char *uuid)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->channels[i] != NULL; i++) {
        if (strcmp(db->channels[i]->uuid, uuid) == 0)
            return db->channels[i];
    }
    return NULL;
}

thread_t *db_get_thread(char *uuid)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->threads[i] != NULL; i++) {
        if (strcmp(db->threads[i]->uuid, uuid) == 0)
            return db->threads[i];
    }
    return NULL;
}

user_t *db_get_user(char *uuid)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->users[i] != NULL; i++) {
        if (strcmp(db->users[i]->uuid, uuid) == 0)
            return db->users[i];
    }
    return NULL;
}
