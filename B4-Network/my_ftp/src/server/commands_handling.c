/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** commands handling
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "server.h"

static int exec_function(server_t *serv, clients_t *client)
{
    cmd_t cmds[] = {{"CDUP", exec_cdup}, {"CWD", exec_cwd},
        {"DELE", exec_dele}, {"HELP", exec_help}, {"LIST", exec_list},
        {"NOOP", exec_noop}, {"PASV", exec_pasv}, {"PORT", exec_port},
        {"PWD", exec_pwd}, {"QUIT", exec_quit}, {"RETR", exec_retr},
        {"STOR", exec_stor}, {"USER", exec_user}, {"PASS", exec_pass}};

    for (size_t i = 0; i < 14; i++) {
        if (strcmp(client->command[0], cmds[i].cmd) == 0) {
            return cmds[i].command(serv, client);
        }
    }
    if (FD_ISSET(client->cli_fd, &serv->wset))
        write(client->cli_fd, "500\n", 4);
    return 0;
}

static int handle_clicmd(server_t *serv, clients_t *client, char *command)
{
    client->command = split_str(command, " \n\r\t");
    if (command[0] == ' ') {
        destroy_clicmd(client);
        if (FD_ISSET(client->cli_fd, &serv->wset))
            write(client->cli_fd, "500\n", 4);
        return 0;
    }
    if (client->command[0] == NULL) {
        destroy_clicmd(client);
        return 0;
    }
    if (FD_ISSET(client->cli_fd, &serv->wset))
        return exec_function(serv, client);
    return 0;
}

static int read_command(server_t *serv, clients_t *client)
{
    char *command = malloc(sizeof(char) * 1024);
    ssize_t len = 0;
    ssize_t readed = 0;

    if (command == NULL)
        return -1;
    for (int i = 0; readed = read(client->cli_fd, command + len, 1023); i++) {
        if (readed <= 0)
            break;
        if (strstr(command, "\n") != NULL) {
            command[len + readed] = '\0';
            return handle_clicmd(serv, client, command);
        }
        len += readed;
        command[len] = '\0';
        command = realloc(command, (i + 1) * 1024 * sizeof(char));
    }
    free(command);
    return readed;
}

int handle_command(server_t *serv, clients_t *clients)
{
    int ret = 0;

    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(clients[i].cli_fd, &serv->rset)) {
            ret = read_command(serv, &clients[i]);
        }
        if (ret == -1 || ret == 84)
            return 84;
    }
    return 0;
}
