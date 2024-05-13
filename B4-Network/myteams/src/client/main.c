/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "../../include/myteams_cli.h"

static void reset_fdset(client_t *client, fd_set *rset, fd_set *wset)
{
    FD_ZERO(rset);
    FD_ZERO(wset);
    FD_SET(STDIN_FILENO, rset);
    FD_SET(client->cli_fd, rset);
    FD_SET(client->cli_fd, wset);
}

static int handle_client_read(client_t *client, fd_set *rset, fd_set *wset)
{
    if (FD_ISSET(STDIN_FILENO, rset)) {
        return handle_client_command(client, wset);
    }
    if (FD_ISSET(client->cli_fd, rset)) {
        if (recv_server(client) == 1)
            return 1;
        return handle_server_response(client);
    }
    return 0;
}

static int loop_client(client_t *client)
{
    fd_set rset;
    fd_set wset;

    while (true) {
        reset_fdset(client, &rset, &wset);
        if (select(client->cli_fd + 1, &rset, &wset, NULL, NULL) < 0 &&
            errno != EINTR) {
            return 84;
        }
        if (handle_client_read(client, &rset, &wset) == 1) {
            printf("Server disconnected\n");
            return 0;
        }
    }
    return 0;
}

static int run_client(char **av)
{
    client_t *client = init_client(av[1], av[2]);
    int ret = 0;

    if (client == NULL)
        return 84;
    printf("Connected to server\n");
    if (connect(client->cli_fd, (struct sockaddr *)&client->cli_adr,
        client->adr_len) != 0) {
        destroy_client(client);
        return 84;
    }
    ret = loop_client(client);
    destroy_client(client);
    return ret;
}

int main(int ac, char **av)
{
    if (ac == 2 && (!strcmp(av[1], "-help") || !strcmp(av[1], "-h")))
        return display_usage();
    if (ac != 3)
        return 84;
    if (!handle_error(av))
        return 84;
    return run_client(av);
}
