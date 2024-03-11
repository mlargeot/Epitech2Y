/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** DELE
*/

#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

static bool handle_delepath(clients_t *client, char *path, server_t *serv)
{
    if (path == NULL)
        return true;
    if (strstr(path, serv->default_dir) == NULL) {
        write(client->cli_fd, "550\n", 4);
        return false;
    }
    return true;
}

static bool handle_deleerr(server_t *serv, clients_t *client)
{
    char *path = NULL;
    char *real_path = NULL;

    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return false;
    }
    if (client->command[1] == NULL) {
        write(client->cli_fd, "501\n", 4);
        return false;
    }
    if (client->command[2] != NULL) {
        write(client->cli_fd, "501\n", 4);
        return false;
    }
    asprintf(&path, "%s/%s", client->working_dir, client->command[1]);
    real_path = realpath(path, real_path);
    return handle_delepath(client, real_path, serv);
}

int exec_dele(server_t *serv, clients_t *client)
{
    if (!handle_deleerr(serv, client))
        return 0;
    if (remove(client->command[1]) == 0)
        write(client->cli_fd, "250\n", 4);
    else
        write(client->cli_fd, "550\n", 4);
    return 0;
}
