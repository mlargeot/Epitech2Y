/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** thread_to_xml
*/

#include "xml.h"
#include "share/thread.h"

xml_t *thread_entity_to_xml(thread_entity_t *thread)
{
    xml_t *node = xml_new("thread");

    xml_new_node(node->root, "uuid", thread->uuid);
    xml_new_node(node->root, "channel_uuid", thread->channel_uuid);
    xml_new_node(node->root, "title", thread->title);
    xml_new_node(node->root, "message", thread->message);
    return node;
}
