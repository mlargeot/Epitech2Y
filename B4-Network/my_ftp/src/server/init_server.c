/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** init
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <strings.h>

#include "server.h"

server_t *destroy_serv(server_t *serv)
{
    if (serv->serv_fd != -1)
        close(serv->serv_fd);
    free(serv);
    return NULL;
}

server_t *init_serv(int port)
{
    server_t *serv = malloc(sizeof(server_t));

    if (serv == NULL)
        return NULL;
    serv->port = port;
    serv->serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    serv->serv_len = sizeof(serv->serv_addr);
    if (serv->serv_fd < 0)
        return destroy_serv(serv);
    serv->serv_addr.sin_family = AF_INET;
    serv->serv_addr.sin_port = htons(port);
    serv->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv->default_dir = getcwd(NULL, 0);
    if (bind(serv->serv_fd, (struct sockaddr *)&serv->serv_addr,
        serv->serv_len) < 0)
        return destroy_serv(serv);
    return serv;
}
