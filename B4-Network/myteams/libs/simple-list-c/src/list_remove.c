/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** list_remove
*/

#include <list.h>

bool list_remove(list_t *list, list_node_t *node)
{
    if (node->host != list)
        return false;
    if (node == list->head)
        list->head = node->next;
    if (node == list->tail)
        list->tail = node->prev;
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;
    list->length--;
    return true;
}
