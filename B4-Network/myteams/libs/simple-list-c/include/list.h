/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** list
*/

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct list_node {
    void *host;
    void *value;
    struct list_node *next;
    struct list_node *prev;
} list_node_t;

typedef struct list_s {
    list_node_t *head;
    list_node_t *tail;
    size_t length;
} list_t;

list_t *list_new(void);
list_node_t *list_get(list_t *list, size_t index);
list_node_t *list_add(list_t *list, void *value);
bool list_remove(list_t *list, list_node_t *node);
void list_free(list_t *list);
void list_clear(list_t *list);
