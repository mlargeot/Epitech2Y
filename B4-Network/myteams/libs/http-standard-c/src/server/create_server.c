/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** create_server
*/

#include <netinet/in.h>
#include <server.h>
#include <stdio.h>

server_t *create_server(int port, list_t *router, map_t *cache)
{
    server_t *server = calloc(1, sizeof(server_t));
    int opt = 1;

    server->socketFd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server->socketFd, SOL_SOCKET,
        SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(port);
    if (bind(server->socketFd, (struct sockaddr *)&server->address,
        sizeof(server->address)) == -1)
        return NULL;
    listen(server->socketFd, 10);
    server->cache = cache ? cache : map_new();
    server->router = router;
    return server;
}
