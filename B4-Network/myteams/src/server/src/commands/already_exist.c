/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** already_exist
*/

#include <myteams_server.h>

int send_already_exist(server_t *server, client_t *client, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "324;\n");
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}
