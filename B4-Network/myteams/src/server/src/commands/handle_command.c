/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** handle_command
*/

#include <myteams_server.h>

static char *get_command(int fd)
{
    char buffer[1025] = {0};
    char *command = NULL;

    if (recv(fd, buffer, 1024, 0) == 0)
        return NULL;
    command = strdup(buffer);
    return command;
}

void remove_first_elem(void **tab)
{
    for (int i = 0; tab[i]; i++)
        tab[i] = tab[i + 1];
}

static int call_command(server_t *server, int i, char *command)
{
    char **req = my_stw(command, ";");
    char **args = NULL;
    char *token = NULL;

    if (lenstw(req) != 2 && lenstw(req) != 1)
        return 1;
    args = mkstw(req[0]);
    token = req[1];
    if (!args || args[0] == NULL)
        return 1;
    if (strcmp(args[0], "/login") == 0)
        return login(server, server->clients[i], args, NULL);
    if (token == NULL || strcmp(token, server->clients[i]->uuid) != 0)
        return unauthorized(server, server->clients[i], args, token);
    for (int j = 0; routes[j].command; j++)
        if (strcmp(routes[j].command, args[0]) == 0)
            return routes[j].handler(server, server->clients[i], args, token);
    return not_found(server, server->clients[i], args, token);
}

static int client_logged_out(server_t *server, int i)
{
    user_t *user = NULL;

    if (server->clients[i]->uuid == NULL)
        return 1;
    user = get_user_from_uuid(server->clients[i]->uuid);
    if (user == NULL)
        return 1;
    server->clients[i]->uuid = NULL;
    send_logout_to_all(server, user);
    server_event_user_logged_out(user->uuid);
    return 0;
}

static int handle_command_client(server_t *server, int i)
{
    char *command = NULL;

    if (FD_ISSET(server->clients[i]->sock, &server->readFds)) {
        command = get_command(server->clients[i]->sock);
        if (!command) {
            printf("Client disconnected\n");
            client_logged_out(server, i);
            close(server->clients[i]->sock);
            remove_first_elem((void **)server->clients + i);
            return 1;
        }
        call_command(server, i, command);
    }
    return 0;
}

int handle_command(server_t *server)
{
    char *command = NULL;

    for (int i = 0; server->clients[i]; i++) {
        if (handle_command_client(server, i))
            break;
    }
    return 0;
}
