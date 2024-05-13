/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** handle server reponse
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "myteams_cli.h"

static void handle_event_code(client_t *client, char **split_in)
{
    for (size_t i = 0; events[i].code != NULL; i++) {
        if (strcmp(events[i].code, split_in[0]) == 0)
            return events[i].handler(client, split_in);
    }
}

int recv_server(client_t *client)
{
    char buffer[1024] = {0};
    ssize_t readed = 0;
    char *tmp = NULL;

    readed = read(client->cli_fd, buffer, 1023);
    if (readed <= 0)
        return 1;
    tmp = strdup(client->server_buffer);
    free(client->server_buffer);
    client->server_buffer = calloc(strlen(tmp) + readed + 1, sizeof(char));
    if (client->server_buffer == NULL)
        return 0;
    strcpy(client->server_buffer, tmp);
    strcat(client->server_buffer, buffer);
    free(tmp);
    return 0;
}

int handle_server_response(client_t *client)
{
    char **split_input = NULL;
    char *rest_of_command = NULL;
    char *backline = NULL;

    if (client->server_buffer == NULL)
        return 0;
    backline = strchr(client->server_buffer, '\n');
    if (backline == NULL)
        return 0;
    rest_of_command = backline + 1;
    *backline = '\0';
    split_input = split_string(client->server_buffer, ";");
    handle_event_code(client, split_input);
    destroy_array(split_input);
    client->server_buffer = strdup(rest_of_command);
    if (strchr(client->server_buffer, '\n') != NULL)
        handle_server_response(client);
    return 0;
}
