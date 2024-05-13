/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_route
*/
#include <regex.h>
#include "router.h"

route_t *find_route(list_t *router, const char *path, method_t method)
{
    regmatch_t matches[10];

    for (list_node_t *node = router->head; node; node = node->next)
        if (regexec(&((route_t *)node->value)->regex_pattern, path, 10,
            matches, 0) == 0 && ((route_t *)node->value)->method == method)
            return node->value;
    return NULL;
}
