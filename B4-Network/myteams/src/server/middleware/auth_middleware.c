/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** auth_middleware
*/

#include <router.h>
#include <server/utils.h>
#include <stdio.h>

bool find_user(list_t *cache, char *token)
{
    if (token == NULL || cache == NULL)
        return false;
    for (list_node_t *node = cache->head; node; node = node->next) {
        if (strcmp(node->value, token) == 0)
            return true;
    }
    return false;
}

bool auth_middleware(request_t *req, response_t *res)
{
    map_node_t *auth = map_get(req->headers, "Authorization");
    map_node_t *cache = map_get(req->cache, "users");
    char *token = NULL;

    if (auth == NULL || cache == NULL) {
        new_unauthorized(res, "Unauthorized need token.");
        return false;
    }
    token = extract_bearer_token(auth->value);
    if (!find_user(cache->value, token)) {
        new_unauthorized(res, "Unauthorized token invalid.");
        return false;
    }
    return true;
}
