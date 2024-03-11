/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** server handling functions
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "server.h"

void reset_socket(server_t *server, clients_t *clients)
{
    FD_ZERO(&server->wset);
    FD_ZERO(&server->rset);
    FD_SET(server->serv_fd, &server->rset);
    FD_SET(server->serv_fd, &server->wset);
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (clients[i].cli_fd != -1) {
            FD_SET(clients[i].cli_fd, &server->rset);
            FD_SET(clients[i].cli_fd, &server->wset);
        }
    }
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (clients[i].cli_fd > server->max_fd)
            server->max_fd = clients[i].cli_fd;
    }
}

static void append_client(server_t *serv, clients_t *clients, int cli_fd)
{
    int pos = 0;

    for (; clients[pos].cli_fd != -1; pos++);
    clients[pos].cli_fd = cli_fd;
    clients[pos].working_dir = strdup(serv->default_dir);
    clients[pos].is_connected = false;
    clients[pos].username = NULL;
    clients[pos].valid_user = false;
    clients[pos].command = NULL;
    clients[pos].status = NEUTRAL;
    clients[pos].data_fd = 0;
    clients[pos].client_data_t = calloc(1, sizeof(data_t));
}

int handle_connection(server_t *serv, clients_t *clients)
{
    int cli_fd = 0;

    if ((FD_ISSET(serv->serv_fd, &serv->rset)) && (!is_full(clients))) {
        cli_fd = accept(serv->serv_fd, (struct sockaddr *)&serv->serv_addr,
            &serv->serv_len);
        if (cli_fd == -1)
            return 84;
        append_client(serv, clients, cli_fd);
    }
    reply_clients(serv, clients);
    return 0;
}
