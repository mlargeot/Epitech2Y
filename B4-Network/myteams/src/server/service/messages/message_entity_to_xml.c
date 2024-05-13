/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** message_entity_to_xml
*/

#include "server.h"
#include <share/message.h>

xml_t *message_entity_to_xml(message_entity_t *message)
{
    xml_t *node = xml_new("message");

    xml_new_node(node->root, "uuid", message->uuid);
    xml_new_node(node->root, "sender_uuid", message->sender_uuid);
    xml_new_node(node->root, "receiver_uuid", message->receiver_uuid);
    xml_new_node(node->root, "content", message->message);
    xml_new_node(node->root, "created_at", ctime(&message->created_at));
    return node;
}
