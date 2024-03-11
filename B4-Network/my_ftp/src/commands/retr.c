/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** RETR
*/

#include "server.h"

static bool handle_retrerr(UNUSED server_t *serv, clients_t *client)
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

int exec_retr(server_t *serv, clients_t *client)
{
    if (!handle_retrerr(serv, client))
        return 0;
    return 0;
}
