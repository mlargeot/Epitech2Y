/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** list_add
*/

#include <list.h>

static void list_add_node(list_t *list, list_node_t *node)
{
    node->host = list;
    list->length++;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
        return;
    }
    node->next = NULL;
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
}

list_node_t *list_add(list_t *list, void *value)
{
    list_node_t *node;

    if (list == NULL)
        return NULL;
    node = calloc(1, sizeof(list_node_t));
    if (node == NULL)
        return NULL;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    list_add_node(list, node);
    return node;
}
