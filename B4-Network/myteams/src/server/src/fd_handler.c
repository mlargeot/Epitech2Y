/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** fd_handler
*/

#include "myteams_server.h"

void set_fd(server_t *server)
{
    FD_ZERO(&server->readFds);
    FD_ZERO(&server->writeFds);
    FD_SET(server->controlSock, &server->readFds);
    FD_SET(server->controlSock, &server->writeFds);
    for (int i = 0; server->clients[i]; i++) {
        FD_SET(server->clients[i]->sock, &server->readFds);
        FD_SET(server->clients[i]->sock, &server->writeFds);
    }
}
