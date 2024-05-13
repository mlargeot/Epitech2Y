/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** user
*/

#include <myteams_server.h>

int send_user(client_t *client, user_t *user)
{
    char *uuid = user->uuid;
    char *username = user->username;
    char *response = NULL;

    asprintf(&response, "337;%s \"%s\" %d;\n",
        uuid, username, user->is_logged);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int send_unknwn_user(client_t *client, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "300;%s;\n", uuid);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int user(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(cmds[1]);

    if (user == NULL)
        return send_unknwn_user(client, cmds[1]);
    send_user(client, user);
    return 0;
}
