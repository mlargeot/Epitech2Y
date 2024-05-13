/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-mychannels-morgan.largeot
** File description:
** channel
*/

#include "db/db.h"

int free_channels(channel_t **channels)
{
    if (channels == NULL)
        return 1;
    for (size_t i = 0; channels[i] != NULL; i++) {
        safe_free(channels[i]->uuid);
        safe_free(channels[i]);
    }
    safe_free(channels);
    return 0;
}

channel_t **db_get_channels(void)
{
    db_t *db = get_set_db(NULL);

    return db->channels;
}

channel_t *db_new_channel(char *name, char *description, team_t *team)
{
    db_t *db = get_set_db(NULL);
    channel_t *new_channel = malloc(sizeof(channel_t));
    size_t len = get_len((void **)db->channels);

    if (new_channel == NULL)
        return NULL;
    new_channel->uuid = uuid_gen(NULL);
    new_channel->name = strdup(name);
    new_channel->description = strdup(description);
    new_channel->team = team;
    if (new_channel->uuid == NULL || new_channel->name == NULL
        || new_channel->description == NULL)
        return NULL;
    db->channels = realloc(db->channels, sizeof(channel_t *) * (len + 2));
    db->channels[len] = new_channel;
    db->channels[len + 1] = NULL;
    return new_channel;
}

int save_channels(FILE *file, channel_t **channels)
{
    size_t len = get_len((void **)channels);

    fwrite(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        fwrite_str(file, channels[i]->uuid);
        fwrite_str(file, channels[i]->name);
        fwrite_str(file, channels[i]->description);
        fwrite_str(file, channels[i]->team->uuid);
    }
    return 0;
}

int load_channels(FILE *file, db_t *db)
{
    size_t len = 0;
    channel_t *new_channel = NULL;

    fread(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        new_channel = malloc(sizeof(channel_t));
        if (new_channel == NULL)
            return 1;
        new_channel->uuid = fread_str(file);
        new_channel->name = fread_str(file);
        new_channel->description = fread_str(file);
        new_channel->team = db_get_team(fread_str(file));
        db->channels = realloc(db->channels, sizeof(channel_t *) * (i + 2));
        db->channels[i] = new_channel;
        db->channels[i + 1] = NULL;
    }
    return 0;
}
