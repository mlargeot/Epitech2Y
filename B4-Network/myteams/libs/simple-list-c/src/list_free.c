/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** list_free
*/

#include <list.h>

void list_free(list_t *list)
{
    if (list == NULL)
        return;
    for (list_node_t *node = list->head; node; node = node->next)
        free(node->value);
    list_clear(list);
    free(list);
}
