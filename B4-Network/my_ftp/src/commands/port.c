/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** PORT
*/

#include "server.h"

static bool set_server_status(clients_t *client)
{
    client->client_data_t->transfer_fd = socket(AF_INET, SOCK_STREAM, 0);
    client->client_data_t->serv_len = sizeof(struct sockaddr_in);
    if (inet_aton(client->client_data_t->ip_adress,
    &client->client_data_t->transfer_socket.sin_addr) == 0) {
        write(client->cli_fd, "501\n", 4);
        return false;
    }
    client->client_data_t->transfer_socket.sin_family = AF_INET;
    client->client_data_t->transfer_socket.sin_port =
        htons(client->client_data_t->port);
    return true;
}

static bool handle_args(clients_t *client)
{
    size_t i = 0;
    char **char_data;
    int data[6] = {-1};

    char_data = split_str(client->command[1], ",");
    for (; char_data[i] != NULL; i++);
    if (i != 6)
        return false;
    if (sscanf(client->command[1], "%d,%d,%d,%d,%d,%d", &data[0],
        &data[1], &data[2], &data[3], &data[4], &data[5]) == EOF)
        return false;
    for (i = 0; i < 6; i++) {
        if (data[i] == -1)
            return false;
    }
    close_cli_datasoc(client);
    asprintf(&client->client_data_t->ip_adress, "%d.%d.%d.%d", data[0],
        data[1], data[2], data[3]);
    client->client_data_t->port = data[4] * 256 + data[5];
    return set_server_status(client);
}

static bool handle_porterr(UNUSED server_t *serv, clients_t *client)
{
    if (client->valid_user != true) {
        write(client->cli_fd, "530\n", 4);
        return false;
    }
    if (client->command[1] == NULL || client->command[2] != NULL) {
        write(client->cli_fd, "501\n", 4);
        return false;
    }
    if (client->status != NEUTRAL) {
        write(client->cli_fd, "503\n", 4);
        return false;
    }
    if (!handle_args(client)) {
        write(client->cli_fd, "501\n", 4);
        return false;
    }
    return true;
}

int exec_port(server_t *serv, clients_t *client)
{
    if (!handle_porterr(serv, client))
        return 0;
    client->status = ACTIVE;
    write(client->cli_fd, "200\n", 4);
    return 0;
}
