/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** find
*/

#include <db/db.h>

channel_t *find_channel_in_team(char *channel_uuid, char *team_uuid)
{
    team_t *team = db_get_team(team_uuid);
    channel_t *channel = NULL;
    channel_t **channels = db_get_channels();

    if (team == NULL)
        return NULL;
    for (int i = 0; channels[i] != NULL; i++) {
        if (strcmp(channels[i]->uuid, channel_uuid) == 0) {
            channel = channels[i];
            break;
        }
    }
    if (strcmp(channel->team->uuid, team_uuid) != 0)
        return NULL;
    return channel;
}

thread_t *find_thread_int_channel(char *thread_uuid, char *channel_uuid)
{
    channel_t *channel = db_get_channel(channel_uuid);
    thread_t *thread = NULL;
    thread_t **threads = db_get_threads();

    if (channel == NULL)
        return NULL;
    for (int i = 0; threads[i] != NULL; i++) {
        if (strcmp(threads[i]->uuid, thread_uuid) == 0) {
            thread = threads[i];
            break;
        }
    }
    if (strcmp(thread->channel->uuid, channel_uuid) != 0)
        return NULL;
    return thread;
}
