/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create_chanel
*/

#include "request.h"
#include "response.h"
#include "share/team.h"
#include <share/channel.h>
#include <server/utils.h>
#include <logging_server.h>
#include <stdio.h>

static channel_dto_t *channel_dto_new(xml_t *body)
{
    channel_dto_t *dto = calloc(1, sizeof(channel_dto_t));

    if (dto == NULL)
        return NULL;
    strcpy(dto->team_uuid,
        xml_get_node_by_tag(body->root, "team_uuid")->inner_text);
    strcpy(dto->name,
        xml_get_node_by_tag(body->root, "name")->inner_text);
    strcpy(dto->description,
        xml_get_node_by_tag(body->root, "description")->inner_text);
    return dto;
}

static channel_entity_t *channel_entity_new(channel_dto_t *data)
{
    channel_entity_t *channel = calloc(1, sizeof(channel_entity_t));

    if (channel == NULL)
        return NULL;
    uuid_gen(channel->uuid);
    strcpy(channel->team_uuid, data->team_uuid);
    strcpy(channel->name, data->name);
    strcpy(channel->description, data->description);
    return channel;
}

static channel_entity_t *get_channel_by_name(map_t *channels, char *name)
{
    channel_entity_t *channel;

    for (map_node_t *node = channels->head; node; node = node->next) {
        channel = node->value;
        if (strcmp(channel->name, name) == 0)
            return channel;
    }
    return NULL;
}

static bool check_dto(channel_dto_t *dto, response_t *res,
    map_node_t *channels)
{
    printf("dto->name: %s\n", dto->name);
    if (dto == NULL) {
        new_bad_request(res, "Invalid body");
        return false;
    }
    if (strlen(dto->name) > 32) {
        new_bad_request(res, "Name too long");
        return false;
    }
    if (strlen(dto->description) > 255) {
        new_bad_request(res, "Description too long");
        return false;
    }
    if (get_channel_by_name(channels->value, dto->name)) {
        new_conflict(res, "Channel already exists");
        return false;
    }
    return true;
}

void create_channel(request_t *req, response_t *res)
{
    channel_dto_t *data = channel_dto_new(req->body);
    channel_entity_t *channel;
    map_node_t *channels = map_get(req->cache, "channels");
    map_node_t *teams = map_get(req->cache, "teams");

    if (!check_dto(data, res, channels))
        return;
    channel = channel_entity_new(data);
    if (map_get(teams->value, channel->team_uuid) == NULL) {
        new_not_found(res, "Team not found");
        return;
    }
    map_add(channels->value, channel->uuid, channel);
    new_created(res, channel_entity_to_xml(channel));
    server_event_channel_created(channel->team_uuid, channel->uuid,
        channel->name);
    free(data);
}
