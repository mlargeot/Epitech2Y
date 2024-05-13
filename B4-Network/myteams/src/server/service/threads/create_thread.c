/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create_thread
*/
#include "request.h"
#include "response.h"
#include <server/utils.h>
#include <share/thread.h>
#include <logging_server.h>

thread_dto_t *thread_dto_new(xml_t *body)
{
    thread_dto_t *dto = calloc(1, sizeof(thread_dto_t));

    if (dto == NULL)
        return NULL;
    strcpy(dto->channel_uuid,
        xml_get_node_by_tag(body->root, "channel_uuid")->inner_text);
    strcpy(dto->title,
        xml_get_node_by_tag(body->root, "title")->inner_text);
    strcpy(dto->message,
        xml_get_node_by_tag(body->root, "message")->inner_text);
    return dto;
}

thread_entity_t *thread_entity_new(thread_dto_t *data)
{
    thread_entity_t *thread = calloc(1, sizeof(thread_entity_t));

    if (!thread)
        return NULL;
    uuid_gen(thread->uuid);
    strcpy(thread->channel_uuid, data->channel_uuid);
    strcpy(thread->title, data->title);
    strcpy(thread->message, data->message);
    return thread;
}

void create_thread(request_t *req, response_t *res)
{
    thread_dto_t *data = thread_dto_new(req->body);
    thread_entity_t *thread;
    map_node_t *channels = map_get(req->cache, "channels");
    char *auth = map_get(req->headers, "Authorization")->value;
    char *token = extract_bearer_token(auth);

    if (!data) {
        new_bad_request(res, "Invalid body");
        return;
    }
    if (!map_get(channels->value, data->channel_uuid)) {
        new_not_found(res, "Channel not found");
        return;
    }
    thread = thread_entity_new(data);
    map_add(map_get(req->cache, "threads")->value, thread->uuid, thread);
    new_created(res, thread_entity_to_xml(thread));
    server_event_thread_created(thread->channel_uuid, thread->uuid,
        token, thread->title, thread->message);
    free(data);
}
