/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** cli_utils
*/

#pragma once

#include "client/myteams_cli.h"
#include <method.h>
#include <response.h>

char **split_str(char *str, char *token);
void destroy_array(char **array);
size_t get_array_size(char **array);
char **mkstw(char *str);
bool is_valid_team(client_t *client, char *uuid);
bool is_valid_thread(client_t *client, char *uuid);
bool is_valid_channel(client_t *client, char *uuid);
bool is_valid_user(client_t *client, char *uuid);
response_t *fetch_url(client_t *client, const char *url,
    method_t method, char *body);
