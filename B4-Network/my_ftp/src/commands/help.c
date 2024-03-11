/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** HELP
*/

#include "server.h"

static bool handle_helperr(clients_t *client)
{
    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return false;
    }
    return true;
}

int exec_help(UNUSED server_t *serv, clients_t *client)
{
    if (!handle_helperr(client))
        return 0;
    write(client->cli_fd, "214 Help message.\n", 18);
    write(client->cli_fd, "-The following commands are recognized.\n", 40);
    write(client->cli_fd, "USER PASS CWD CDUP QUIT DELE PWD PASV PORT"
    " HELP NOOP RETR STOR LIST\n", 68);
    write(client->cli_fd, "214\n", 4);
    return 0;
}
