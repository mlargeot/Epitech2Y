/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** team_entity_to_xml
*/

#include <xml.h>
#include "share/team.h"

xml_t *team_entity_to_xml(team_entity_t *team)
{
    xml_t *node = xml_new("team");

    xml_new_node(node->root, "uuid", team->uuid);
    xml_new_node(node->root, "name", team->name);
    xml_new_node(node->root, "description", team->description);
    return node;
}
