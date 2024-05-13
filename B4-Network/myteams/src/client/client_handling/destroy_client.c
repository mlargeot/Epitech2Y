/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** destroy
*/

#include <stdlib.h>
#include <unistd.h>

#include "client/myteams_cli.h"

void destroy_client(client_t *client)
{
    if (client == NULL)
        return;
    if (client->cli_fd > 0)
        close(client->cli_fd);
    if (!client->cli_uuid)
        free(client->cli_uuid);
    if (!client->cli_url)
        free(client->cli_url);
    if (!client->cli_username)
        free(client->cli_username);
    free(client);
    client = NULL;
}
