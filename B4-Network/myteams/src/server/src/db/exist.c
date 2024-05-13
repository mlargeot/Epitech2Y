/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** exist
*/

#include "db/db.h"

int is_team_exist(char *team_name)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->teams[i] != NULL; i++) {
        if (strcmp(db->teams[i]->name, team_name) == 0)
            return 1;
    }
    return 0;
}

int is_channel_exist(char *channel_name, team_t *team)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->channels[i] != NULL; i++) {
        if (strcmp(db->channels[i]->name, channel_name) == 0
            && db->channels[i]->team->uuid == team->uuid)
            return 1;
    }
    return 0;
}

int is_thread_exist(char *thread_name, channel_t *channel)
{
    db_t *db = get_set_db(NULL);

    for (size_t i = 0; db->threads[i] != NULL; i++) {
        if (strcmp(db->threads[i]->title, thread_name) == 0
            && db->threads[i]->channel->uuid == channel->uuid)
            return 1;
    }
    return 0;
}
