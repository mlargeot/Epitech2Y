/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** NOOP
*/

#include "server.h"

int exec_noop(UNUSED server_t *serv, clients_t *client)
{
    if (client->valid_user == false) {
        write(client->cli_fd, "530\n", 4);
        return 0;
    }
    write(client->cli_fd, "200\n", 4);
    return 0;
}
