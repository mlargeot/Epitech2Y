/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** connect_data_tranfer
*/

#include "server.h"

static int connect_active_mod(clients_t *client)
{
    int fd = client->client_data_t->transfer_fd;

    if (fd == -1)
        return -1;
    if (connect(fd, (struct sockaddr *)&client->client_data_t->transfer_socket,
        client->client_data_t->serv_len) == -1)
        return -1;
    client->data_fd = fd;
    return 0;
}

static int connect_passive_mod(clients_t *client)
{
    struct sockaddr_in sock_client = {0};
    int fd = accept(client->client_data_t->transfer_fd,
        (struct sockaddr *)&sock_client, &client->client_data_t->serv_len);

    if (fd == -1)
        return -1;
    client->data_fd = fd;
    return 0;
}

int connect_data_transfer(clients_t *client)
{
    if (client->status == ACTIVE) {
        return connect_active_mod(client);
    } else if (client->status == PASSIVE) {
        return connect_passive_mod(client);
    } else {
        return -1;
    }
}
