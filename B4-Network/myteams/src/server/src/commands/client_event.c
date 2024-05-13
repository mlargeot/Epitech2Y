/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** client_event
*/

#include <myteams_server.h>

int ping_new_team(server_t *server, team_t *team)
{
    char *uuid = team->uuid;
    char *name = team->name;
    char *description = team->description;
    char *response = NULL;

    asprintf(&response, "100;%s \"%s\" \"%s\";\n", uuid, name, description);
    for (int i = 0; server->clients[i]; i++) {
        if (server->clients[i]->uuid != NULL)
            send(server->clients[i]->sock, response, strlen(response), 0);
    }
    free(response);
    return 0;
}
