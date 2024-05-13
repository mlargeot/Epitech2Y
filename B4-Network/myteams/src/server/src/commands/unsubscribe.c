/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** unsubscribe
*/

#include <myteams_server.h>

int send_unsubscribed(server_t *server, client_t *client,
    user_t *user, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "471;\"%s\" %s;\n", user->uuid, uuid);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int unsubscribe(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(token);
    team_t *team = db_get_team(cmds[1]);
    int nb_teams = 0;

    if (team == NULL)
        return send_team_not_found(server, client, cmds[1]);
    for (int i = 0; user->teams[i]; i++) {
        if (strcmp(user->teams[i]->uuid, team->uuid) == 0) {
            remove_first_elem((void **)(user->teams + i));
            server_event_user_unsubscribed(team->uuid, user->uuid);
            return send_unsubscribed(server, client, user, team->uuid);
        }
    }
    return 0;
}
