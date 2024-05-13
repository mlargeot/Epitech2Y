/*
** EPITECH PROJECT, 2024
** simple-c-map
** File description:
** map_add
*/

#include <map.h>
#include <stdlib.h>
#include <string.h>

void map_add_node(map_t *map, map_node_t *node)
{
    if (map == NULL || node == NULL)
        return;
    node->host = map;
    map->length++;
    if (map->tail == NULL) {
        map->head = node;
        map->tail = node;
        return;
    }
    node->next = NULL;
    map->tail->next = node;
    node->prev = map->tail;
    map->tail = node;
}

map_node_t *map_add(map_t *map, char *key, void *value)
{
    map_node_t *node;

    if (map == NULL || key == NULL)
        return NULL;
    if (map_get(map, key) != NULL)
        return NULL;
    node = calloc(1, sizeof(map_node_t));
    if (node == NULL)
        return NULL;
    node->value = value;
    node->key = strdup(key);
    map_add_node(map, node);
    return node;
}
