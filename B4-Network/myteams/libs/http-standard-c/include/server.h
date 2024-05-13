/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** server
*/

#pragma once

#include "router.h"
#include <netinet/in.h>

typedef struct server_s {
    int socketFd;
    struct sockaddr_in address;
    map_t *cache;
    list_t *router;
} server_t;

server_t *create_server(int port, list_t *router, map_t *cache);
int start_server(int port, list_t *router, map_t *cache);
void handle_request(int clientFd, server_t *server);
void convert_path_to_regex(const char *template_path, char *regex_buffer);
