/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** handle_request
*/

#include <request.h>
#include <response.h>
#include <router.h>
#include <unistd.h>
#include <stdio.h>
#include <server.h>

void handle_request(int client_fd, server_t *server)
{
    request_t *request = calloc(1, sizeof(request_t));
    response_t *response;

    if (request == NULL) {
        close(client_fd);
        return;
    }
    request->headers = map_new();
    request->params = map_new();
    request->cache = server->cache;
    if (!parse_request(client_fd, request)) {
        close(client_fd);
        return;
    }
    response = handle_route(server->router, request);
    if (response == NULL)
        return;
    send_response(client_fd, response);
    free_response(response);
    free_request(request);
}
