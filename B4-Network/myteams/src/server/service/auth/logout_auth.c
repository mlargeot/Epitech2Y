/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** auth_logged_out
*/
#include "request.h"
#include "response.h"
#include <server/utils.h>
#include <logging_server.h>

static list_node_t *find_logged_user(list_t *users, char *token)
{
    for (list_node_t *node = users->head; node; node = node->next)
        if (strcmp(node->value, token) == 0)
            return node;
    return NULL;
}

void logout_auth(request_t *req, response_t *res)
{
    map_node_t *cache_users = map_get(req->cache, "users");
    list_node_t *user;
    list_t *users;
    map_node_t *bearer = map_get(req->headers, "Authorization");
    char *token;

    if (cache_users == NULL || bearer == NULL) {
        new_unauthorized(res, "Unauthorized");
        return;
    }
    users = cache_users->value;
    token = extract_bearer_token(bearer->value);
    user = find_logged_user(users, token);
    if (user == NULL) {
        new_unauthorized(res, "Unauthorized");
        return;
    }
    list_remove(users, user);
    server_event_user_logged_out(token);
    new_ok(res, NULL);
}
