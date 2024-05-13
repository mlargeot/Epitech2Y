/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** send request to server
*/

#include <string.h>

#include "client/myteams_cli.h"
#include <logging_client.h>

void send_serv_request(client_t *client, char **cmd)
{
    for (size_t i = 0; cmds[i].command; i++) {
        if (strcmp(cmd[0], cmds[i].command) != 0)
            continue;
        if (cmds[i].need_login && !client->cli_logged) {
            printf("You need to be logged in to use this command\n");
            client_error_unauthorized();
            return;
        }
        return cmds[i].handler(client, cmd);
    }
}
