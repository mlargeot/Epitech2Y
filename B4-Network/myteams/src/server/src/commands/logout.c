/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** logout
*/

#include <myteams_server.h>

static int send_logout_user(client_t *client, user_t *user)
{
    char *uuid = user->uuid;
    char *username = user->username;
    char *response = NULL;

    asprintf(&response, "501;%s \"%s\";\n", uuid, username);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int send_logout_to_all(server_t *server, user_t *user)
{
    char *uuid = user->uuid;
    char *username = user->username;
    char *response = NULL;

    asprintf(&response, "60;%s \"%s\";\n", uuid, username);
    for (int i = 0; server->clients[i]; i++) {
        if (server->clients[i]->uuid != NULL)
            send(server->clients[i]->sock, response, strlen(response), 0);
    }
    free(response);
    return 0;
}

int logout(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = get_user_from_uuid(token);

    if (user == NULL)
        return 0;
    send_logout_to_all(server, user);
    send_logout_user(client, user);
    server_event_user_logged_out(user->uuid);
    client->uuid = NULL;
    user->is_logged = 0;
    return 0;
}
