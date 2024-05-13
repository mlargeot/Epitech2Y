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

#include "client/myteams_cli.h"

static int loop_client(client_t *client)
{
    while (true) {
        if (handle_client_command(client) == 84)
            return 84;
    }
    return 0;
}

static int run_client(char **av)
{
    client_t *client = init_client(av[1], av[2]);

    if (client == NULL)
        return 84;
    if (loop_client(client) == 84) {
        destroy_client(client);
        return 84;
    }
    destroy_client(client);
    return 0;
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
