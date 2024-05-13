/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_channel
*/

#include "request.h"
#include "response.h"
#include <share/channel.h>

void get_channels(request_t *req, response_t *res)
{
    map_t *channels = map_get(req->cache, "channels")->value;
    xml_t *data = xml_new("channels");

    for (map_node_t *node = channels->head; node; node = node->next)
        xml_add_node(data->root, channel_entity_to_xml(node->value)->root);
    new_ok(res, data);
}

void get_channel_by_uuid(request_t *req, response_t *res)
{
    map_node_t *uuid_node = map_get(req->params, "channelUuid");
    map_t *channels = map_get(req->cache, "channels")->value;
    map_node_t *channel;

    if (uuid_node == NULL) {
        new_bad_request(res, "Invalid pram");
        return;
    }
    channel = map_get(channels, uuid_node->value);
    if (channel == NULL) {
        new_not_found(res, "Channel not found");
        return;
    }
    new_ok(res, channel_entity_to_xml(channel->value));
}
