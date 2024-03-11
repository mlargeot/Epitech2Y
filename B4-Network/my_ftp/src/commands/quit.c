/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** QUIT
*/

#include <stdlib.h>

#include "server.h"

int exec_quit(UNUSED server_t *serv, clients_t *client)
{
    write(client->cli_fd, "221\n", 4);
    close(client->cli_fd);
    client->cli_fd = -1;
    destroy_clicmd(client);
    reset_user(client);
    free(client->working_dir);
    client->is_connected = false;
    return 0;
}
