/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** simple_bis
*/

#include "db/db.h"

comment_t *db_get_comment(char *uuid)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->comments[i] != NULL; i++) {
        if (strcmp(db->comments[i]->uuid, uuid) == 0)
            return db->comments[i];
    }
    return NULL;
}

message_t *db_get_message(char *uuid)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->messages[i] != NULL; i++) {
        if (strcmp(db->messages[i]->uuid, uuid) == 0)
            return db->messages[i];
    }
    return NULL;
}

user_t *get_user_from_username(char *username)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->users[i] != NULL; i++) {
        if (strcmp(db->users[i]->username, username) == 0)
            return db->users[i];
    }
    return NULL;
}

user_t *get_user_from_uuid(char *uuid)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->users[i] != NULL; i++) {
        if (strcmp(db->users[i]->uuid, uuid) == 0)
            return db->users[i];
    }
    return NULL;
}

int is_user_subscribed(user_t *user, team_t *team)
{
    for (size_t i = 0; user->teams[i] != NULL; i++) {
        if (strcmp(user->teams[i]->uuid, team->uuid) == 0)
            return 1;
    }
    return 0;
}
