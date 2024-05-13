/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create
*/

#include "client/myteams_cli.h"

void create(client_t *client, char **command)
{
    switch (client->scope.scope) {
        case NONE:
            create_team(client, command);
            break;
        case TEAMS:
            create_channel(client, command);
            break;
        case CHANNELS:
            create_thread(client, command);
            break;
        case THREADS:
            create_reply(client, command);
            break;
    }
}
