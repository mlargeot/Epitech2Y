/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** start_server
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#include "server.h"

static int loop_serv(server_t *serv)
{
    clients_t clients[FD_SETSIZE] = {0};

    serv->max_fd = serv->serv_fd;
    reset_clients_fd(clients);
    while (1) {
        reset_socket(serv, clients);
        if (select(serv->max_fd + 1, &serv->rset, &serv->wset, NULL, NULL) < 0)
            return 84;
        if (handle_connection(serv, clients) == 84)
            return 84;
        if (handle_command(serv, clients) == 84)
            return 84;
    }
    return 0;
}

int start_server(int port)
{
    server_t *serv = init_serv(port);

    if (serv == NULL) {
        fprintf(stderr, "Error during init process.\n");
        return 84;
    }
    if (listen(serv->serv_fd, 250) < 0) {
        fprintf(stderr, "Listening error.\n");
        destroy_serv(serv);
        return 84;
    }
    if (loop_serv(serv) == 84) {
        fprintf(stderr, "Error during server process.\n");
        return 84;
    }
    destroy_serv(serv);
    return 0;
}
