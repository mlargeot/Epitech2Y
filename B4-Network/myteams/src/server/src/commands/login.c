/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** login
*/

#include <myteams_server.h>

static int send_created_user(client_t *client, user_t *user)
{
    char *uuid = user->uuid;
    char *username = user->username;
    char *response = NULL;

    asprintf(&response, "500;%s \"%s\";\n", uuid, username);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int send_login(server_t *server, client_t *client, user_t *user)
{
    char *uuid = user->uuid;
    char *username = user->username;
    char *response = NULL;

    asprintf(&response, "49;%s \"%s\";\n", uuid, username);
    for (int i = 0; server->clients[i]; i++) {
        if (server->clients[i]->uuid != NULL)
            send(server->clients[i]->sock, response, strlen(response), 0);
    }
    free(response);
    return 0;
}

int login(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = get_user_from_username(cmds[1]);

    if (user == NULL) {
        db_new_user(cmds[1], strdup("password"));
        user = get_user_from_username(cmds[1]);
        server_event_user_created(user->uuid, user->username);
    }
    client->uuid = user->uuid;
    send_login(server, client, user);
    send_created_user(client, user);
    server_event_user_logged_in(client->uuid);
    user->is_logged = 1;
    return 0;
}
