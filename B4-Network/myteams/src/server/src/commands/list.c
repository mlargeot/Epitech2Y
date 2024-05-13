/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** list
*/

#include <myteams_server.h>

static int send_teams_user(server_t *server, client_t *client, user_t *user)
{
    team_t **teams = db_get_teams();
    char *response = NULL;
    char *tmp = NULL;

    asprintf(&response, "169;");
    for (int i = 0; teams[i]; i++) {
        asprintf(&tmp, "%s\"%s\" \"%s\" \"%s\";", response,
            teams[i]->uuid, teams[i]->name, teams[i]->description);
        free(response);
        response = tmp;
        tmp = NULL;
    }
    asprintf(&tmp, "%s\n", response);
    send(client->sock, tmp, strlen(tmp), 0);
    free(response);
    return 0;
}

static int send_channels_user(server_t *server, client_t *client, user_t *user)
{
    channel_t **channels = get_channels_from_team(user->context_uuid);
    char *response = NULL;
    char *tmp = NULL;

    if (channels == NULL)
        return 0;
    asprintf(&response, "186;");
    for (int i = 0; channels[i]; i++) {
        asprintf(&tmp, "%s\"%s\" \"%s\" \"%s\";", response,
            channels[i]->uuid, channels[i]->name, channels[i]->description);
        free(response);
        response = tmp;
        tmp = NULL;
    }
    asprintf(&tmp, "%s\n", response);
    send(client->sock, tmp, strlen(tmp), 0);
    free(response);
    return 0;
}

static int send_threads_user(server_t *server, client_t *client, user_t *user)
{
    thread_t **threads = get_threads_from_channel(user->context_uuid);
    char *response = NULL;
    char *tmp = NULL;
    char *timestamp = NULL;

    if (threads == NULL)
        return 0;
    asprintf(&response, "205;");
    for (int i = 0; threads[i]; i++) {
        timestamp = get_time_str(threads[i]->timestamp);
        asprintf(&tmp, "%s\"%s\" \"%s\" \"%s\" \"%s\" \"%s\";", response,
            threads[i]->uuid, threads[i]->user->uuid, timestamp,
            threads[i]->title, threads[i]->message);
        free(response);
        response = tmp;
        tmp = NULL;
    }
    asprintf(&tmp, "%s\n", response);
    send(client->sock, tmp, strlen(tmp), 0);
    return 0;
}

static int send_comments_user(server_t *server, client_t *client, user_t *user)
{
    comment_t **comments = db_get_comments_from_thread(user->context_uuid);
    char *response = NULL;
    char *tmp = NULL;
    char *timestamp = NULL;

    asprintf(&response, "222;");
    for (int i = 0; comments[i]; i++) {
        timestamp = get_time_str(comments[i]->timestamp);
        asprintf(&tmp, "%s\"%s\" \"%s\" \"%s\" \"%s\";", response,
            comments[i]->uuid, comments[i]->user->uuid,
            timestamp, comments[i]->message);
        free(response);
        response = tmp;
        tmp = NULL;
    }
    asprintf(&tmp, "%s\n", response);
    send(client->sock, tmp, strlen(tmp), 0);
    free(response);
    return 0;
}

int list(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(token);

    if (user->context == UNDEFINED)
        send_teams_user(server, client, user);
    if (user->context == TEAM)
        send_channels_user(server, client, user);
    if (user->context == CHANNEL)
        send_threads_user(server, client, user);
    if (user->context == THREAD)
        send_comments_user(server, client, user);
    return 0;
}
