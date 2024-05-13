/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** new_client
*/

#include <myteams_server.h>

client_t *init_client(server_t *server, int newSock,
    struct sockaddr_in *newAddr)
{
    client_t *newClient = malloc(sizeof(client_t));

    if (!newClient)
        return (NULL);
    newClient->sock = newSock;
    newClient->adr = *newAddr;
    newClient->adr_len = sizeof(newAddr);
    newClient->uuid = NULL;
    return (newClient);
}

int tab_len(void **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

void new_client(server_t *server)
{
    int newSock = 0;
    struct sockaddr_in newAddr = {0};
    socklen_t addr_size = sizeof(server->controlAddr);
    client_t *newClient = NULL;
    int clientCount = tab_len((void **)server->clients);

    if (FD_ISSET(server->controlSock, &server->readFds)) {
        newSock = accept(server->controlSock, (SA *)&newAddr, &addr_size);
        if (newSock < 0)
            return;
        newClient = init_client(server, newSock, &newAddr);
        server->clients = realloc(server->clients,
            sizeof(client_t *) * (clientCount + 2));
        server->clients[clientCount] = newClient;
        server->clients[clientCount + 1] = NULL;
        printf("New client connected\n");
    }
}
