/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** unauthorized
*/

#include <myteams_server.h>

int unauthorized(server_t *server, client_t *client,
    char **cmds, char *token)
{
    send(client->sock, "311;\n", 5, 0);
    return 0;
}
