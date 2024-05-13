/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_channels
*/

#include "db/db.h"

channel_t **get_channels_from_team(char *uuid)
{
    db_t *db = get_set_db(NULL);
    channel_t **channels = NULL;
    size_t len = 0;

    for (size_t i = 0; db->channels[i] != NULL; i++) {
        if (strcmp(db->channels[i]->team->uuid, uuid) == 0) {
            channels = realloc(channels, sizeof(channel_t *) * (len + 2));
            channels[len] = db->channels[i];
            channels[len + 1] = NULL;
            len++;
        }
    }
    return channels;
}

thread_t **get_threads_from_channel(char *uuid)
{
    db_t *db = get_set_db(NULL);
    thread_t **threads = NULL;
    size_t len = 0;

    for (size_t i = 0; db->threads[i] != NULL; i++) {
        if (strcmp(db->threads[i]->channel->uuid, uuid) == 0) {
            threads = realloc(threads, sizeof(thread_t *) * (len + 2));
            threads[len] = db->threads[i];
            threads[len + 1] = NULL;
            len++;
        }
    }
    return threads;
}

user_t **get_users_from_team(char *uuid)
{
    db_t *db = get_set_db(NULL);
    user_t **users = NULL;
    size_t len = 0;

    for (size_t i = 0; db->users[i] != NULL; i++) {
        if (is_user_in_team(db->users[i]->uuid, uuid)) {
            users = realloc(users, sizeof(user_t *) * (len + 2));
            users[len] = db->users[i];
            users[len + 1] = NULL;
            len++;
        }
    }
    return users;
}
