/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** user_entity_to_xml
*/

#include <xml.h>
#include <share/user.h>

xml_t *user_entity_to_xml(user_entity_t *user)
{
    xml_t *node = xml_new("user");

    xml_new_node(node->root, "uuid", user->uuid);
    xml_new_node(node->root, "username", user->username);
    return node;
}
