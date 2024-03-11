/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** PASV
*/

#include "server.h"

static bool handle_pasverr(UNUSED server_t *serv, clients_t *client)
{
    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return false;
    }
    if (client->command[1] != NULL) {
        write(client->cli_fd, "501\n", 4);
        return false;
    }
    return true;
}

static int open_newsocket(clients_t *client)
{
    client->client_data_t->transfer_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->client_data_t->transfer_fd == -1) {
        write(client->cli_fd, "425\n", 4);
        return -1;
    }
    client->client_data_t->serv_len = sizeof(struct sockaddr_in);
    client->client_data_t->transfer_socket.sin_family = AF_INET;
    client->client_data_t->transfer_socket.sin_port = htons(0);
    client->client_data_t->transfer_socket.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(client->client_data_t->transfer_fd,
        (struct sockaddr *)&client->client_data_t->transfer_socket,
        client->client_data_t->serv_len) == -1) {
        write(client->cli_fd, "425\n", 4);
        return -1;
    }
    if (listen(client->client_data_t->transfer_fd, SOMAXCONN) == -1) {
        write(client->cli_fd, "425\n", 4);
        return -1;
    }
    return 0;
}

static int get_client_data(clients_t *client)
{
    int ip_nb[4] = {0};

    client->client_data_t->ip_adress = inet_ntoa(
        client->client_data_t->transfer_socket.sin_addr);
    client->client_data_t->port = ntohs(
        client->client_data_t->transfer_socket.sin_port);
    sscanf(client->client_data_t->ip_adress, "%d.%d.%d.%d", &ip_nb[0],
        &ip_nb[1], &ip_nb[2], &ip_nb[3]);
    dprintf(client->cli_fd, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d).\n",
        ip_nb[0], ip_nb[1], ip_nb[2], ip_nb[3],
        client->client_data_t->port / 256, client->client_data_t->port % 256);
    return 0;
}

int exec_pasv(server_t *serv, clients_t *client)
{
    if (!handle_pasverr(serv, client))
        return 0;
    close_cli_datasoc(client);
    client->status = PASSIVE;
    if (open_newsocket(client) == -1) {
        client->status = NEUTRAL;
        return 0;
    }
    getsockname(client->client_data_t->transfer_fd,
    (struct sockaddr *)&client->client_data_t->transfer_socket,
    &client->client_data_t->serv_len);
    get_client_data(client);
    return 0;
}
