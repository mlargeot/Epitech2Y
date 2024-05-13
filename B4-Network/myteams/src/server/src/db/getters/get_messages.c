/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_messages
*/

#include "db/db.h"

static message_t **get_messages_of_user(char *uuid)
{
    message_t **all_msgs = db_get_messages();
    message_t **messages = NULL;
    int len = 0;

    for (int i = 0; all_msgs[i]; i++) {
        if (strcmp(all_msgs[i]->sender->uuid, uuid) == 0
            || strcmp(all_msgs[i]->receiver->uuid, uuid) == 0) {
            messages = realloc(messages, sizeof(message_t *) * (len + 2));
            messages[len] = all_msgs[i];
            messages[len + 1] = NULL;
            len++;
        }
    }
    return messages;
}

message_t **db_get_messages_between(char *uuid1, char *uuid2)
{
    message_t **all_msgs = get_messages_of_user(uuid1);
    message_t **messages = NULL;
    int len = 0;

    for (int i = 0; all_msgs[i]; i++) {
        if (strcmp(all_msgs[i]->sender->uuid, uuid2) == 0
            || strcmp(all_msgs[i]->receiver->uuid, uuid2) == 0) {
            messages = realloc(messages, sizeof(message_t *) * (len + 2));
            messages[len] = all_msgs[i];
            messages[len + 1] = NULL;
            len++;
        }
    }
    free_messages(all_msgs);
    return messages;
}
