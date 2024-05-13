/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** server
*/

#include <myteams_server.h>

void init_server_bis(server_t *server, int port)
{
    server->controlAddr.sin_family = AF_INET;
    server->controlAddr.sin_addr.s_addr = INADDR_ANY;
    server->controlAddr.sin_port = htons(port);
    server->clients = malloc(sizeof(client_t *));
    server->clients[0] = NULL;
    server->port = port;
}

server_t *init_server(int port)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        return (NULL);
    server->controlSock = socket(AF_INET, SOCK_STREAM, 0);
    if (server->controlSock == -1)
        return (NULL);
    init_server_bis(server, port);
    if (bind(server->controlSock, (struct sockaddr *)&server->controlAddr,
        sizeof(server->controlAddr)) == -1) {
        printf("Bind error\n");
        return (NULL);
    }
    if (listen(server->controlSock, 10) == -1)
        return (NULL);
    return (server);
}

static int server_select(server_t *server)
{
    if (select(FD_SETSIZE + 1, &server->readFds,
        &server->writeFds, NULL, NULL) < 0)
        printf("Select error\n");
    return 0;
}

int loop(server_t *server)
{
    init_db();
    load_db("db.txt");
    while (1) {
        set_fd(server);
        server_select(server);
        new_client(server);
        handle_command(server);
    }
    return (0);
}
