/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** request
*/

#pragma once

#include <method.h>
#include <stddef.h>
#include <stdbool.h>
#include <config.h>
#include <xml.h>
#include "map.h"

typedef struct {
    char *path;
    struct route_t *route;
    xml_t *body;
    method_t method;

    map_t *headers;
    map_t *params;
    map_t *cache;
} request_t;

bool parse_request(int sockfd, request_t *request);
void free_request(request_t *request);
