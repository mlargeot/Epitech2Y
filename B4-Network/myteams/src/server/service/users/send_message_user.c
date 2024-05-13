/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** send_message_user
*/
#include "request.h"
#include "response.h"
#include <share/message.h>
#include <share/user.h>
#include <server/utils.h>
#include <logging_server.h>

static message_dto_t *message_dto_new(char *receiver, xml_t *body)
{
    message_dto_t *dto = calloc(1, sizeof(message_dto_t));

    if (!dto)
        return NULL;
    strcpy(dto->receiver_uuid, receiver);
    strcpy(dto->message, body->root->inner_text);
    return dto;
}

static message_entity_t *message_entity_new(char *sender, message_dto_t *data)
{
    message_entity_t *message = calloc(1, sizeof(message_entity_t));

    if (!message)
        return NULL;
    uuid_gen(message->uuid);
    strcpy(message->receiver_uuid, data->receiver_uuid);
    strcpy(message->message, data->message);
    strcpy(message->sender_uuid, sender);
    message->created_at = time(NULL);
    return message;
}

static bool is_user_exist(list_t *users, char *uuid)
{
    for (list_node_t *elem = users->head; elem; elem = elem->next)
        if (strcmp(((user_entity_t *)elem->value)->uuid, uuid) == 0)
            return true;
    return false;
}

static bool check_dto(message_dto_t *dto, response_t *res, map_node_t *users)
{
    if (!dto) {
        new_bad_request(res, "Invalid body");
        return false;
    }
    if (strlen(dto->message) > 255) {
        new_bad_request(res, "Message too long");
        return false;
    }
    if (!is_user_exist(users->value, dto->receiver_uuid)) {
        new_not_found(res, "User not found");
        return false;
    }
    return true;
}

void send_message_to_user(request_t *req, response_t *res)
{
    char *token = map_get(req->headers, "Authorization")->value;
    char *receiver_uuid = map_get(req->params, "receiverUuid")->value;
    message_dto_t *data = message_dto_new(receiver_uuid, req->body);
    message_entity_t *message;

    if (!check_dto(data, res, map_get(req->cache, "users"))) {
        free(data);
        return;
    }
    token = extract_bearer_token(token);
    if (strcmp(data->receiver_uuid, token) == 0) {
        new_bad_request(res, "You can't send message to yourself");
        return;
    }
    message = message_entity_new(token, data);
    map_add(map_get(req->cache, "messages")->value, message->uuid, message);
    new_created(res, message_entity_to_xml(message));
    server_event_private_message_sended(message->sender_uuid,
        message->receiver_uuid, message->message);
    free(data);
}
