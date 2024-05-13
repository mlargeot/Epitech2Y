/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** event handling
*/

#include <stdlib.h>
#include <string.h>

#include "logging_client.h"
#include "myteams_cli.h"

void handle_user_logout(client_t *client, UNUSED char **serv_resp)
{
    free(client->cli_uuid);
    client->cli_uuid = NULL;
    free(client->username);
    client->username = NULL;
}

void handle_user_login(client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client->cli_uuid = strdup(splited_body[0]);
    client->username = strdup(splited_body[1]);
    destroy_array(splited_body);
}
