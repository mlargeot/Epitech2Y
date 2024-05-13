/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** add_route
*/

#include <router.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <list.h>

static void parse_and_store_param_names(const char *template_path,
    char param_names[10][256], size_t *param_count)
{
    const char *cursor = template_path;
    size_t name_len;

    *param_count = 0;
    while (*cursor) {
        if (*cursor != ':') {
            cursor++;
            continue;
        }
        name_len = 0;
        cursor++;
        while (*cursor != '/' && *cursor != '\0' && name_len < 255) {
            param_names[*param_count][name_len] = *cursor;
            name_len++;
            cursor++;
        }
        param_names[*param_count][name_len] = '\0';
        (*param_count)++;
    }
}

static void end_of_string(route_t *route, char *dest,
    const char *regex_pattern)
{
    *dest = '$';
    dest++;
    *dest = '\0';
    if (regcomp(&route->regex_pattern, regex_pattern, REG_EXTENDED) != 0)
        fprintf(stderr, "Failed to compile regex: %s\n", regex_pattern);
}

static void compile_regex_for_route(route_t *route)
{
    char regex_pattern[1024];
    const char *src = route->template_path;
    char *dest = regex_pattern;

    *dest = '^';
    dest++;
    while (*src) {
        if (*src != ':') {
            *dest = *src;
            dest++;
            src++;
            continue;
        }
        strcpy(dest, "([^/]+)");
        dest += strlen("([^/]+)");
        while (*src && *src != '/')
            src++;
    }
    end_of_string(route, dest, regex_pattern);
}

const char *method_to_string(method_t method)
{
    for (int i = 0; methods[i].string != NULL; i++) {
        if (methods[i].method == method)
            return methods[i].string;
    }
    return NULL;
}

route_t *add_route(list_t *router, route_config_t config)
{
    route_t *new_entry = malloc(sizeof(route_t));

    if (new_entry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    new_entry->template_path = strdup(config.template_path);
    new_entry->method = config.method;
    new_entry->middleware = config.middleware;
    new_entry->handler = config.handler;
    parse_and_store_param_names(config.template_path,
        new_entry->param_names,
        &new_entry->param_count);
    compile_regex_for_route(new_entry);
    list_add(router, new_entry);
    printf("[%s] %s\n", method_to_string(config.method), config.template_path);
    return new_entry;
}
