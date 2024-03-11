/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** CDUP
*/

#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "server.h"

int handle_path(char *n_path, char *def_path)
{
    FILE *fp;

    if (n_path == NULL)
        return 1;
    if (strstr(n_path, def_path) != NULL)
        return 1;
    fp = fopen(n_path, "r");
    if (fp == NULL)
        return 1;
    fclose(fp);
    return 0;
}

int exec_cdup(server_t *serv, clients_t *client)
{
    char *path = NULL;
    char *new_path = NULL;

    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return 0;
    }
    if (client->command[1] != NULL) {
        write(client->cli_fd, "501\n", 4);
        return 0;
    }
    asprintf(&path, "%s/../", client->working_dir);
    new_path = realpath(path, new_path);
    if (handle_path(new_path, serv->default_dir) == 1) {
        write(client->cli_fd, "250\n", 4);
        free(client->working_dir);
        client->working_dir = strdup(new_path);
    } else
        write(client->cli_fd, "550\n", 4);
    return 0;
}
