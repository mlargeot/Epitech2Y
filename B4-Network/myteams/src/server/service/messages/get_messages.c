/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_message
*/
#include "request.h"
#include "response.h"
#include <share/message.h>
#include <server/utils.h>

void get_messages_by_receiver_uuid(request_t *req, response_t *res)
{
    map_t *messages = map_get(req->cache, "messages")->value;
    char *receiver_uuid = map_get(req->params, "receiverUuid")->value;
    char *token = map_get(req->headers, "Authorization")->value;
    xml_t *node_msg = xml_new("messages");
    char *temp_receiver_uuid = NULL;
    char *temp_sender_uuid = NULL;

    token = extract_bearer_token(token);
    for (map_node_t *node = messages->head; node; node = node->next) {
        temp_receiver_uuid = ((message_entity_t *)node->value)->receiver_uuid;
        temp_sender_uuid = ((message_entity_t *)node->value)->sender_uuid;
        if ((strcmp(temp_receiver_uuid, receiver_uuid) != 0 &&
            strcmp(temp_sender_uuid, receiver_uuid) != 0) ||
            (strcmp(temp_sender_uuid, token) != 0 &&
            strcmp(temp_receiver_uuid, token) != 0))
            continue;
        xml_add_node(node_msg->root, message_entity_to_xml(node->value)->root);
    }
    new_ok(res, node_msg);
}
