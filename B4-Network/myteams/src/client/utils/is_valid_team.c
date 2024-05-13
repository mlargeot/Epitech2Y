/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** is_valid_team
*/

#include <request.h>
#include <response.h>
#include "client/myteams_cli.h"
#include <stdio.h>

bool is_valid_team(client_t *client, char *uuid)
{
    response_t *response;
    char *route = NULL;
    char *authorization = NULL;
    status_code_t status_code;
    request_config_t config;

    asprintf(&route, "%s/teams/%s", client->cli_url, uuid);
    asprintf(&authorization, "Bearer %s", client->cli_uuid);
    config = new_config(GET, NULL, authorization);
    response = fetch(route, &config);
    free(route);
    free(authorization);
    status_code = response->status_code;
    response_free(response);
    return status_code == OK;
}
