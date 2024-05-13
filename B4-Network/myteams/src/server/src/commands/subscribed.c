/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** subscribed
*/

#include <myteams_server.h>

int send_subscribed_to_teams(server_t *server,
    client_t *client, user_t **users, char *uuid)
{
    char *response = NULL;
    char *tmp = NULL;

    asprintf(&response, "151;");
    for (int i = 0; users[i]; i++) {
        if (is_user_in_team(users[i]->uuid, uuid)) {
            asprintf(&tmp, "%s\"%s\" \"%s\" \"%d\";", response,
                users[i]->uuid, users[i]->username, users[i]->is_logged);
            free(response);
            response = tmp;
            tmp = NULL;
        }
    }
    asprintf(&tmp, "%s\n", response);
    send(client->sock, tmp, strlen(tmp), 0);
    return 0;
}

int send_teams_user(server_t *server, client_t *client, user_t *user)
{
    char *response = NULL;
    char *tmp = NULL;

    asprintf(&response, "169;");
    for (int i = 0; user->teams[i]; i++) {
        asprintf(&tmp, "%s\"%s\" \"%s\" \"%s\";", response,
            user->teams[i]->uuid, user->teams[i]->name,
            user->teams[i]->description);
        free(response);
        response = tmp;
        tmp = NULL;
    }
    asprintf(&tmp, "%s\n", response);
    send(client->sock, tmp, strlen(tmp), 0);
    free(response);
    return 0;
}

int subscribed(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t **users = db_get_users();
    user_t *user = db_get_user(token);

    if (lenstw(cmds) == 2)
        send_subscribed_to_teams(server, client, users, cmds[1]);
    if (lenstw(cmds) == 1) {
        send_teams_user(server, client, user);
    }
    return 0;
}
