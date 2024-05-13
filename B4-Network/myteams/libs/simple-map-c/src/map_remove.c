/*
** EPITECH PROJECT, 2024
** simple-c-map
** File description:
** map_remove
*/
#include <map.h>
#include <stdbool.h>
#include <stdlib.h>

bool map_remove(map_t *map, char *key)
{
    map_node_t *node = map_get(map, key);

    if (node == NULL)
        return false;
    if (node->host != map)
        return false;
    if (node == map->head)
        map->head = node->next;
    if (node == map->tail)
        map->tail = node->prev;
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;
    map->length--;
    return true;
}
