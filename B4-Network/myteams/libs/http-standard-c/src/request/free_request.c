/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_request
*/

#include <request.h>
#include <stdlib.h>
#include <map.h>

void free_request(request_t *request)
{
    for (map_node_t *node = request->params->head; node; node = node->next) {
        free(node->key);
        free(node->value);
    }
    free(request->params);
    for (map_node_t *node = request->headers->head; node; node = node->next) {
        free(node->value);
        free(node->key);
    }
    free(request->headers);
    xml_free(request->body);
}
