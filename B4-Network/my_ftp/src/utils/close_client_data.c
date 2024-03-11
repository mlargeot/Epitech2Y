/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** close client data transfer socket
*/

#include <string.h>

#include "server.h"

int close_cli_datasoc(clients_t *client)
{
    if (client->client_data_t->transfer_fd != 0) {
        close(client->client_data_t->transfer_fd);
        client->client_data_t->transfer_fd = 0;
    }
    return 0;
}
