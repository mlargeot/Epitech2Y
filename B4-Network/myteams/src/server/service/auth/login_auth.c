/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** auth_logged_in
*/
#include <request.h>
#include <response.h>
#include <share/user.h>
#include <server/utils.h>
#include <logging_server.h>
#include <stdio.h>

static bool is_user_login(list_t *users, char *username)
{
    for (list_node_t *node = users->head; node; node = node->next)
        if (strcmp(((user_entity_t *)node->value)->username, username) == 0)
            return true;
    return false;
}

user_entity_t *get_user_by_name(list_t *users, char *username)
{
    for (list_node_t *node = users->head; node; node = node->next)
        if (strcmp(((user_entity_t *)node->value)->username, username) == 0)
            return node->value;
    return NULL;
}

user_dto_t *user_dto_new(xml_t *body)
{
    user_dto_t *dto = calloc(1, sizeof(user_dto_t));

    if (!dto)
        return NULL;
    strcpy(dto->username, body->root->inner_text);
    return dto;
}

user_entity_t *user_entity_new(user_dto_t *data)
{
    user_entity_t *user = calloc(1, sizeof(user_entity_t));

    if (!user)
        return NULL;
    uuid_gen(user->uuid);
    strcpy(user->username, data->username);
    return user;
}

void login_auth(request_t *req, response_t *res)
{
    user_dto_t *data = user_dto_new(req->body);
    list_t *users = map_get(req->cache, "users")->value;
    user_entity_t *user = get_user_by_name(users, data->username);

    if (user == NULL)
        user = user_entity_new(data);
    new_ok(res, user_entity_to_xml(user));
    if (!is_user_login(users, data->username)) {
        list_add(users, user);
        server_event_user_created(user->uuid, user->username);
    }
    server_event_user_logged_in(user->uuid);
    free(data);
}
