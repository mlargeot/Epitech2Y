/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_messages
*/

#include "db/db.h"

message_t **db_get_messages_from_user(char *uuid)
{
    db_t *db = get_set_db(NULL);
    message_t **messages = NULL;
    size_t len = 0;

    for (size_t i = 0; db->messages[i] != NULL; i++) {
        if (strcmp(db->messages[i]->sender->uuid, uuid) == 0
        || strcmp(db->messages[i]->receiver->uuid, uuid) == 0) {
            messages = realloc(messages, sizeof(message_t *) * (len + 2));
            messages[len] = db->messages[i];
            messages[len + 1] = NULL;
            len++;
        }
    }
    return messages;
}

message_t **db_get_messages_user_to_user(char *uuid_sender,
    char *uuid_receiver)
{
    db_t *db = get_set_db(NULL);
    message_t **messages = NULL;
    size_t len = 0;

    for (size_t i = 0; db->messages[i] != NULL; i++) {
        if (strcmp(db->messages[i]->sender->uuid, uuid_sender) == 0
        && strcmp(db->messages[i]->receiver->uuid, uuid_receiver) == 0) {
            messages = realloc(messages, sizeof(message_t *) * (len + 2));
            messages[len] = db->messages[i];
            messages[len + 1] = NULL;
            len++;
        }
    }
    return messages;
}
