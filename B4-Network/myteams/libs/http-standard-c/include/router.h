/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** path
*/

#pragma once

#include <method.h>
#include <request.h>
#include <response.h>
#include <sys/queue.h>
#include <regex.h>
#include <stdbool.h>
#include <config.h>
#include <list.h>

typedef struct route_t {
    char *template_path;
    regex_t regex_pattern;
    char param_names[PARAM_ARRAY_SIZE][PARAM_SIZE];
    size_t param_count;
    method_t method;
    bool (*middleware)(request_t *, response_t *);
    void (*handler)(request_t *, response_t *);
} route_t;

typedef struct {
    char *template_path;
    method_t method;
    bool (*middleware)(request_t *, response_t *);
    void (*handler)(request_t *, response_t *);
} route_config_t;

route_t *add_route(list_t *router, route_config_t config);
route_t *find_route(list_t *router, const char *path, method_t method);
response_t *handle_route(list_t *router, request_t *request);
void extract_params(request_t *request);
