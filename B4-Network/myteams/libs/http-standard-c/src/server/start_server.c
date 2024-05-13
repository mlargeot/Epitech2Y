/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** start_server
*/

#include <server.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int start_server(int port, list_t *router, map_t *cache)
{
    server_t *server = create_server(port, router, cache);
    struct sockaddr_in client_address;
    socklen_t client_address_len;
    int client_fd;

    if (server->socketFd == -1)
        return 84;
    printf("Server started on port %d\n", port);
    while (true) {
        client_address_len = sizeof(client_address);
        client_fd = accept(server->socketFd,
            (struct sockaddr *)&client_address, &client_address_len);
        if (client_fd == -1) {
            printf("Failed to accept connection");
            continue;
        }
        handle_request(client_fd, server);
        close(client_fd);
    }
}
