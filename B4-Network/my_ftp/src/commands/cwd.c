/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** CWD
*/

#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

static int handle_cwderr(clients_t *client)
{
    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return 1;
    }
    if (client->command[1] == NULL) {
        write(client->cli_fd, "501\n", 4);
        return 1;
    }
    if (client->command[2] != NULL) {
        write(client->cli_fd, "501\n", 4);
        return 1;
    }
    return 0;
}

int exec_cwd(server_t *serv, clients_t *client)
{
    char *path = NULL;
    char *n_path = NULL;

    if (handle_cwderr(client) == 1)
        return 0;
    asprintf(&path, "%s/%s", client->working_dir, client->command[1]);
    n_path = realpath(path, n_path);
    if (n_path == NULL) {
        write(client->cli_fd, "550\n", 4);
    } else if (handle_path(n_path, serv->default_dir) == 1) {
        write(client->cli_fd, "250\n", 4);
        free(client->working_dir);
        client->working_dir = strdup(n_path);
    } else
        write(client->cli_fd, "550\n", 4);
    return 0;
}
