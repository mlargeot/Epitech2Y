/*
** EPITECH PROJECT, 2022
** c-map.h
** File description:
** desc
*/
#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct map_node {
    char *key;
    void *host;
    void *value;
    struct map_node *next;
    struct map_node *prev;
} map_node_t;

typedef struct map {
    map_node_t *head;
    map_node_t *tail;
    size_t length;
} map_t;

map_t *map_new(void);
map_node_t *map_get(map_t *map, char *key);
map_node_t *map_add(map_t *map, char *key, void *value);
bool map_remove(map_t *map, char *key);
map_node_t *map_set(map_t *map, char *key, void *value);
