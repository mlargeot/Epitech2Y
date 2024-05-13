/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** main
*/

#include "myteams_server.h"

int usage(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\tport is the port number on which the server socket listens.\n");
    return 0;
}

int main(int ac, char **av, char **env)
{
    server_t *server = NULL;

    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return (usage());
    if (ac != 2)
        return (84);
    server = init_server(atoi(av[1]));
    if (!server)
        return (84);
    if (!server)
        return (84);
    return loop(server);
}
