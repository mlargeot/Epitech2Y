/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** subscribe
*/

#include <myteams_server.h>

static int send_subscribe(server_t *server, client_t *client,
    user_t *user, char *uuid)
{
    char *response = NULL;

    asprintf(&response, "461;%s %s;\n", user->uuid, uuid);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int subscribe(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(token);
    team_t *team = db_get_team(cmds[1]);
    int nb_teams = 0;

    if (team == NULL)
        return 1;
    if (is_user_subscribed(user, team))
        return 1;
    nb_teams = tab_len((void **)user->teams);
    user->teams = realloc(user->teams, sizeof(char *) * (nb_teams + 2));
    user->teams[nb_teams] = team;
    user->teams[nb_teams + 1] = NULL;
    server_event_user_subscribed(team->uuid, user->uuid);
    return send_subscribe(server, client, user, team->uuid);
    return 0;
}
