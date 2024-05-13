/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** use
*/
#include "client/myteams_cli.h"
#include <request.h>
#include <client/cli_utils.h>

void set_scope(client_t *client, char **command)
{
    size_t size = get_array_size(command);

    if (size >= 2) {
        strcpy(client->scope.teams, command[1]);
        client->scope.scope = TEAMS;
    }
    if (size >= 3) {
        strcpy(client->scope.channel, command[2]);
        client->scope.scope = CHANNELS;
    }
    if (size == 4) {
        strcpy(client->scope.thread, command[3]);
        client->scope.scope = THREADS;
    }
}

bool check_scope(client_t *client, char **command)
{
    size_t size = get_array_size(command);

    if (size >= 2 && !is_valid_team(client, command[1])) {
        printf("Invalid team uuid\n");
        return false;
    }
    if (size >= 3 && !is_valid_channel(client, command[2])) {
        printf("Invalid channel uuid\n");
        return false;
    }
    if (size == 4 && !is_valid_thread(client, command[3])) {
        printf("Invalid thread uuid\n");
        return false;
    }
    return true;
}

void use(client_t *client, char **command)
{
    if (get_array_size(command) < 2 || get_array_size(command) > 4) {
        printf("Invalid number of arguments\n");
        return;
    }
    if (!check_scope(client, command))
        return;
    set_scope(client, command);
    printf("Scope set\n");
    printf("Team: %s\n", client->scope.teams);
    printf("Channel: %s\n", client->scope.channel);
    printf("Thread: %s\n", client->scope.thread);
}
