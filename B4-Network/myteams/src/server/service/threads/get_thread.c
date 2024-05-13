/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_thread
*/
#include "request.h"
#include "response.h"
#include <share/thread.h>
#include <share/thread_reply.h>

void get_threads(request_t *req, response_t *res)
{
    map_t *threads = map_get(req->cache, "threads")->value;
    xml_t *data = xml_new("threads");

    for (map_node_t *node = threads->head; node; node = node->next)
        xml_add_node(data->root, thread_entity_to_xml(node->value)->root);
    new_ok(res, data);
}

void get_thread_by_uuid(request_t *req, response_t *res)
{
    map_node_t *uuid_node = map_get(req->params, "threadUuid");
    map_t *threads = map_get(req->cache, "threads")->value;
    map_node_t *thread;

    if (uuid_node == NULL) {
        new_bad_request(res, "Invalid pram");
        return;
    }
    thread = map_get(threads, uuid_node->value);
    if (thread == NULL) {
        new_not_found(res, "Thread not found");
        return;
    }
    new_ok(res, thread_entity_to_xml(thread->value));
}

void get_thread_replays(request_t *req, response_t *res)
{
    map_node_t *uuid_node = map_get(req->params, "threadUuid");
    map_t *threads = map_get(req->cache, "threads")->value;
    map_t *replays = map_get(req->cache, "threads_replays")->value;
    map_node_t *thread;
    xml_t *data = xml_new("threads_replays");

    if (uuid_node == NULL) {
        new_bad_request(res, "Invalid pram");
        return;
    }
    thread = map_get(threads, uuid_node->value);
    replays = map_get(replays, uuid_node->value)->value;
    if (thread == NULL || replays == NULL) {
        new_not_found(res, "Thread not found");
        return;
    }
    for (map_node_t *node = replays->head; node; node = node->next)
        xml_add_node(data->root,
            thread_reply_entity_to_xml(node->value)->root);
    new_ok(res, data);
}
