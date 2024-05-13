/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** list_get
*/

#include <list.h>

list_node_t *list_get(list_t *list, size_t index)
{
    size_t i = 0;

    if (list == NULL)
        return NULL;
    for (list_node_t *node = list->head; node; node = node->next) {
        if (index == i)
            return node;
        i++;
    }
    return NULL;
}
