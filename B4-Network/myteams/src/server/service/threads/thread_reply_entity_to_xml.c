/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** thread_reply_entity_to_xml
*/

#include "xml.h"
#include "share/thread_reply.h"

xml_t *thread_reply_entity_to_xml(thread_reply_entity_t *thread_reply)
{
    xml_t *node = xml_new("thread_reply");

    xml_new_node(node->root, "uuid", thread_reply->uuid);
    xml_new_node(node->root, "thread_uuid", thread_reply->thread_uuid);
    xml_new_node(node->root, "author_uuid", thread_reply->author_uuid);
    xml_new_node(node->root, "message", thread_reply->message);
    return node;
}
