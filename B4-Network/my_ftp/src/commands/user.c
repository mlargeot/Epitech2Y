/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** USER + PASS
*/

#include <string.h>
#include <stdlib.h>

#include "server.h"

int reset_user(clients_t *client)
{
    if (client->valid_user == true)
        client->valid_user = false;
    if (client->username != NULL)
        free(client->username);
    client->username = NULL;
    return 0;
}

int exec_pass(UNUSED server_t *serv, clients_t *client)
{
    if (client->valid_user == true) {
        write(client->cli_fd, "530\n", 4);
        return 0;
    }
    if (client->username == NULL) {
        write(client->cli_fd, "503\n", 4);
    } else if (strcmp(client->username, "Anonymous") == 0 &&
        client->command[1] == NULL) {
        write(client->cli_fd, "230\n", 4);
        client->valid_user = true;
    } else {
        write(client->cli_fd, "530\n", 4);
        return 0;
    }
    return 0;
}

int exec_user(UNUSED server_t *serv, clients_t *client)
{
    reset_user(client);
    if (client->command[1] != NULL) {
        if (client->command[2] != NULL) {
            write(client->cli_fd, "501\n", 4);
            return 0;
        }
        client->username = strdup(client->command[1]);
    } else {
        write(client->cli_fd, "501\n", 4);
        return 0;
    }
    write(client->cli_fd, "331\n", 4);
    return 0;
}
