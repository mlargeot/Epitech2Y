/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** LIST
*/

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "server.h"

static bool handle_listerr(UNUSED server_t *serv, clients_t *client)
{
    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return false;
    }
    if (client->status == NEUTRAL) {
        write(client->cli_fd, "503\n", 4);
        return false;
    }
    return true;
}

static void get_list(clients_t *client, char *path)
{
    FILE *fp = NULL;
    char buf[1024] = {0};
    char *ls_cmd = NULL;

    asprintf(&ls_cmd, "ls %s", path);
    fp = popen(ls_cmd, "r");
    free(ls_cmd);
    if (fp == NULL) {
        write(client->cli_fd, "426\n", 4);
        return;
    }
    while (fgets(buf, 1023, fp) != NULL) {
        write(client->data_fd, buf, strlen(buf));
        memset(buf, 0, 1023);
    }
    write(client->cli_fd, "226\n", 4);
    pclose(fp);
}

static int handle_list(UNUSED server_t *serv, clients_t *client, char *path)
{
    pid_t pid = 0;

    if (strstr(path, serv->default_dir) == NULL) {
        write(client->cli_fd, "550\n", 4);
        return 0;
    }
    if (connect_data_transfer(client) == -1) {
        write(client->cli_fd, "425\n", 4);
        return 0;
    }
    pid = fork();
    if (pid == -1) {
        write(client->cli_fd, "425\n", 4);
    } else if (pid == 0) {
        write(client->cli_fd, "150\n", 4);
        get_list(client, path);
        free(path);
    }
    return 0;
}

int exec_list(server_t *serv, clients_t *client)
{
    char *path = NULL;
    char *n_path = NULL;

    if (!handle_listerr(serv, client))
        return 0;
    if (client->command[1] != NULL)
        asprintf(&path, "%s/%s", client->working_dir, client->command[1]);
    else
        asprintf(&path, "%s", client->working_dir);
    n_path = realpath(path, n_path);
    if (n_path == NULL)
        write(client->cli_fd, "550\n", 4);
    else
        handle_list(serv, client, n_path);
    close_cli_datasoc(client);
    client->status = NEUTRAL;
    return 0;
}
