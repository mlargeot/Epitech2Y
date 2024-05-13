/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** not_found
*/

#include <myteams_server.h>

int not_found(server_t *server, client_t *client,
    char **cmds, char *token)
{
    return 0;
}

int send_user_not_found(server_t *server, client_t *client, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "300;%s;\n", uuid);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int send_team_not_found(server_t *server, client_t *client, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "263;%s;\n", uuid);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int send_channel_not_found(server_t *server, client_t *client, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "276;%s;\n", uuid);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int send_thread_not_found(server_t *server, client_t *client, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "288;%s;\n", uuid);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}
