/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** channel_entity_to_xml
*/

#include <xml.h>
#include "share/channel.h"

xml_t *channel_entity_to_xml(channel_entity_t *channel)
{
    xml_t *node = xml_new("channel");

    xml_new_node(node->root, "uuid", channel->uuid);
    xml_new_node(node->root, "team_uuid", channel->team_uuid);
    xml_new_node(node->root, "name", channel->name);
    xml_new_node(node->root, "description", channel->description);
    return node;
}
