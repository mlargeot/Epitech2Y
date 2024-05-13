/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** utils_str_match
*/

#include "utils.h"

const char *split_array[] = {".*"};

char *str_match(char *buf, char *match)
{
    list_t *split = str_split_list(match, 1, split_array);
    int start_index;

    if (split == NULL)
        return NULL;
    start_index = str_index_of(buf, list_get(split, 0)->value);
    if (start_index == -1) {
        list_free(split);
        return NULL;
    }
    if (split->length == 1)
        return buf + start_index;
    for (list_node_t *node = split->head->next; node; node = node->next) {
        if (str_index_of(buf, node->value) == -1) {
            list_free(split);
            return NULL;
        }
    }
    list_free(split);
    return buf + start_index;
}
