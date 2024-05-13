/*
** EPITECH PROJECT, 2024
** simple-c-map
** File description:
** map_set
*/
#include <map.h>
#include <string.h>

map_node_t *map_set(map_t *map, char *key, void *value)
{
    map_node_t *node = map_get(map, key);

    if (node == NULL)
        return NULL;
    node->value = value;
    return node;
}
