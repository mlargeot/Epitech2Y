/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** init
*/

#include <stdlib.h>
#include <string.h>

#include "myteams_cli.h"

client_t *init_client(char *ip, char *port)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->cli_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->cli_fd < 0) {
        free(client);
        return NULL;
    }
    memset(&client->cli_adr, 0, sizeof(client->cli_adr));
    client->cli_adr.sin_family = AF_INET;
    client->cli_adr.sin_port = htons(atoi(port));
    client->cli_adr.sin_addr.s_addr = inet_addr(ip);
    client->cli_uuid = NULL;
    client->server_buffer = calloc(1, sizeof(char));
    client->adr_len = sizeof(client->cli_adr);
    return client;
}
