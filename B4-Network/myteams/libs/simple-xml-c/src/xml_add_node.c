/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** xml_add_node
*/

#include "xml.h"

void xml_add_node(xml_node_t *node, xml_node_t *new_node)
{
    new_node->parent = node;
    list_add(node->list_children, new_node);
}
