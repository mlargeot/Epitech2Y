/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** PWD
*/

#include <string.h>

#include "server.h"

int exec_pwd(server_t *serv, clients_t *client)
{
    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return 0;
    }
    if (client->command[1] != NULL) {
        write(client->cli_fd, "501\n", 4);
        return 0;
    }
    write(client->cli_fd, "257 \"", 5);
    if (client->working_dir[strlen(serv->default_dir)] == '\0')
        write(client->cli_fd, "/", 1);
    else {
        write(client->cli_fd, client->working_dir + strlen(serv->default_dir),
            strlen((client->working_dir + strlen(serv->default_dir))));
    }
    write(client->cli_fd, "\"\n", 2);
    return 0;
}
