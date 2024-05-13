/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** logout command client side
*/

#include "client/myteams_cli.h"
#include "logging_client.h"
#include "request.h"
#include <client/cli_utils.h>

static void handle_response(client_t *client, response_t *response)
{
    if (response == NULL)
        return;
    if (response->status_code == OK) {
        client_event_logged_out(client->cli_uuid, client->cli_username);
        free(client->cli_uuid);
        client->cli_uuid = NULL;
        free(client->cli_username);
        client->cli_username = NULL;
        printf("%d - Client successfully logged out.\n", OK);
    } else {
        printf("%d - %s\n", response->status_code, response->status_message);
    }
}

void logout(client_t *client, char **command)
{
    response_t *response;
    char *route = NULL;
    char *authorization = NULL;
    request_config_t config;

    if (command != NULL && get_array_size(command) != 1) {
        printf("Invalid command format\n");
        return;
    }
    asprintf(&route, "%s/auth/logout", client->cli_url);
    asprintf(&authorization, "Bearer %s", client->cli_uuid);
    config = new_config(POST, NULL, authorization);
    response = fetch(route, &config);
    free(route);
    free(authorization);
    handle_response(client, response);
    response_free(response);
}
