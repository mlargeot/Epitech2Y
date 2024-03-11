/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** client_list_handling
*/

#include <stddef.h>
#include <stdlib.h>

#include "server.h"

void destroy_clicmd(clients_t *client)
{
    if (client->command == NULL)
        return;
    if (client->command[0] != NULL) {
        for (size_t i = 0; client->command[i] != NULL; i++) {
            free(client->command[i]);
        }
    }
    free(client->command);
    client->command = NULL;
}

void reset_clients_fd(clients_t *cli)
{
    for (int i = 0; i < FD_SETSIZE; i++)
        cli[i].cli_fd = -1;
}

bool is_full(clients_t *clients)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (clients[i].cli_fd == -1)
            return false;
    }
    return true;
}

void reply_clients(server_t *serv, clients_t *clients)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(clients[i].cli_fd, &serv->wset) &&
            clients[i].is_connected == false) {
                write(clients[i].cli_fd, "220\n", 4);
                clients[i].is_connected = true;
        }
    }
}
