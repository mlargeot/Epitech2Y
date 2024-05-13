/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** send request to server
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "myteams_cli.h"

static char *concat_strings(char *final_str, char *cmd_str)
{
    char *result = NULL;

    asprintf(&result, "%s \"%s\"", final_str, cmd_str);
    free(final_str);
    return result;
}

static char *concat_uuid(char *final_str, char *uuid)
{
    char *result = NULL;

    if (uuid != NULL) {
        asprintf(&result, "%s ;%s", final_str, uuid);
        free(final_str);
        return result;
    } else {
        asprintf(&result, "%s ;", final_str);
        free(final_str);
        return result;
    }
}

static char *concat_send_req(char **cmd, char *uuid)
{
    char *final_str = strdup(cmd[0]);

    for (size_t i = 1; i != get_array_size(cmd); i++)
        final_str = concat_strings(final_str, cmd[i]);
    final_str = concat_uuid(final_str, uuid);
    return final_str;
}

static void handle_send(client_t *client, char **cmd, fp_t cmds, fd_set *wset)
{
    char *send_str = NULL;

    if ((cmds.nb_max_args < get_array_size(cmd) - 1) ||
        (cmds.nb_min_args > get_array_size(cmd) - 1)) {
        printf("Invalid args number!\n");
        return;
    }
    if (cmds.handler != NULL) {
        if (!cmds.handler(cmd))
            return;
    }
    send_str = concat_send_req(cmd, client->cli_uuid);
    if (send_str != NULL) {
        if (FD_ISSET(client->cli_fd, wset)) {
            send(client->cli_fd, send_str, strlen(send_str), 0);
            free(send_str);
        }
    }
}

void send_serv_request(client_t *client, char **cmd, fd_set *wset)
{
    for (size_t i = 0; cmds[i].command; i++) {
        if (strcmp(cmd[0], "/help") == 0)
            return help();
        if (strcmp(cmd[0], cmds[i].command) == 0)
            return handle_send(client, cmd, cmds[i], wset);
    }
}
