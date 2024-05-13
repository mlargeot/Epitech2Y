/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** users
*/

#include <myteams_server.h>

int users(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t **users = db_get_users();
    char *response = NULL;
    char *tmp = NULL;

    asprintf(&response, "151;");
    for (int i = 0; users[i]; i++) {
        asprintf(&tmp, "%s\"%s\" \"%s\" \"%d\";", response,
            users[i]->uuid, users[i]->username, users[i]->is_logged);
        free(response);
        response = tmp;
        tmp = NULL;
    }
    asprintf(&tmp, "%s\n", response);
    send(client->sock, tmp, strlen(tmp), 0);
    free(response);
    return 0;
}
