/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** login command client side
*/

#include <string.h>
#include <stdio.h>

#include "logging_client.h"
#include "client/myteams_cli.h"
#include <client/cli_utils.h>
#include "xml.h"
#include "share/user.h"
#include "request.h"

char *user_dto_to_str(user_dto_t *dto)
{
    xml_t *user = xml_new("username");
    char *str;

    user->root->inner_text = strdup(dto->username);
    str = xml_str(user);
    xml_free(user);
    return str;
}

static void handle_response(client_t *client, response_t *response)
{
    xml_t *body;

    if (response == NULL)
        return;
    body = xml_new(NULL);
    xml_parser(body, response->body);
    printf("200 - Succesfully logged in! uuid: %s\n",
    xml_get_node_by_tag(body->root, "uuid")->inner_text);
    client->cli_username = strdup(
        xml_get_node_by_tag(body->root, "username")->inner_text);
    client->cli_uuid = strdup(
        xml_get_node_by_tag(body->root, "uuid")->inner_text);
    client_event_logged_in(client->cli_uuid,
        xml_get_node_by_tag(body->root, "username")->inner_text);
    client->cli_logged = true;
}

request_config_t new_config(enum method_e method, char *body,
    char *authorization)
{
    if (authorization) {
        return (request_config_t){
            .method = method,
            .headers = {
                {"Content-Type", "application/xml"},
                {"Authorization", authorization},
                {NULL, NULL}
            },
            .body = body
        };
    }
    return (request_config_t){
        .method = method,
        .headers = {
            {"Content-Type", "application/xml"},
            {NULL, NULL}
        },
        .body = body
    };
}

void login(client_t *client, char **command)
{
    user_dto_t dto = {0};
    response_t *response;
    request_config_t config;
    char *route = NULL;

    if (get_array_size(command) != 2) {
        printf("Invalid command format\n");
        return;
    }
    strcpy(dto.username, command[1]);
    asprintf(&route, "%s/auth/login", client->cli_url);
    config = new_config(POST, user_dto_to_str(&dto), NULL);
    response = fetch(route, &config);
    handle_response(client, response);
    response_free(response);
    free(route);
}
