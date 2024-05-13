/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** replay_thread
*/
#include "request.h"
#include "response.h"
#include <share/thread.h>
#include <share/thread_reply.h>
#include <server/utils.h>
#include <logging_server.h>
#include <stdio.h>

thread_reply_dto_t *thread_reply_dto_new(xml_t *body)
{
    thread_reply_dto_t *dto = calloc(1, sizeof(thread_reply_dto_t));

    if (dto == NULL)
        return NULL;
    strcpy(dto->message,
        xml_get_node_by_tag(body->root, "message")->inner_text);
    return dto;
}

thread_reply_entity_t *thread_reply_entity_new(char *user_uuid,
    char *thread_uuid, thread_reply_dto_t *data)
{
    thread_reply_entity_t *reply = calloc(1, sizeof(thread_reply_entity_t));

    if (reply == NULL)
        return NULL;
    uuid_gen(reply->uuid);
    strcpy(reply->message, data->message);
    strcpy(reply->author_uuid, user_uuid);
    strcpy(reply->thread_uuid, thread_uuid);
    return reply;
}

static thread_entity_t *get_thread_from_uuid(map_t *threads,
    map_node_t *uuid_node, response_t *res)
{
    char *uuid = uuid_node->value;
    map_node_t *thread = map_get(threads, uuid);

    if (!thread) {
        new_not_found(res, "Thread not found");
        return NULL;
    }
    return thread->value;
}

static void create_and_add_reply(map_t *threads_replays,
    char *thread_uuid, thread_reply_entity_t *reply, response_t *res)
{
    map_node_t *replays = map_get(threads_replays, thread_uuid);

    if (!replays) {
        replays = map_add(threads_replays, thread_uuid, map_new());
        map_add(threads_replays, thread_uuid, replays);
    }
    map_add(replays->value, reply->uuid, reply);
    new_ok(res, thread_reply_entity_to_xml(reply));
}

void reply_thread(request_t *req, response_t *res)
{
    char *token;
    thread_reply_dto_t *data;
    thread_reply_entity_t *reply;
    thread_entity_t *thread;
    map_node_t *uuid_node = map_get(req->params, "threadUuid");
    map_t *threads = map_get(req->cache, "threads")->value;

    thread = get_thread_from_uuid(threads, uuid_node, res);
    if (!thread) {
        new_bad_request(res, "Invalid parameter");
        return;
    }
    token = extract_bearer_token(
        map_get(req->headers, "Authorization")->value);
    data = thread_reply_dto_new(req->body);
    reply = thread_reply_entity_new(token, uuid_node->value, data);
    create_and_add_reply(map_get(req->cache, "threads_replays")->value,
        ((thread_entity_t *)thread)->uuid, reply, res);
    server_event_reply_created(reply->thread_uuid, token, reply->message);
    free(data);
}
