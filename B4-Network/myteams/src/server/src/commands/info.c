/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** info
*/

#include <myteams_server.h>

static int send_info(server_t *server, client_t *client, user_t *user)
{
    char *response = NULL;

    asprintf(&response, "337;\"%s\" \"%s\" \"%d\";\n",
        user->uuid, user->username, user->is_logged);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

static int send_team_info(server_t *server, client_t *client, user_t *user)
{
    team_t *team = db_get_team(user->context_uuid);
    char *response = NULL;

    asprintf(&response, "352;\"%s\" \"%s\" \"%s\";\n",
        team->uuid, team->name, team->description);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

static int send_channel_info(server_t *server, client_t *client, user_t *user)
{
    channel_t *channel = db_get_channel(user->context_uuid);
    char *response = NULL;

    asprintf(&response, "367;\"%s\" \"%s\" \"%s\";\n",
        channel->uuid, channel->name, channel->description);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

static int send_thread_info(server_t *server, client_t *client, user_t *user)
{
    thread_t *thread = db_get_thread(user->context_uuid);
    char *response = NULL;
    char *timestamp = NULL;

    asprintf(&response, "384;\"%s\" \"%s\" \"%s\" \"%s\";\n",
        thread->uuid, timestamp, thread->title, thread->message);
    send(client->sock, response, strlen(response), 0);
    free(response);
    return 0;
}

int info(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(token);

    if (user == NULL)
        return send_user_not_found(server, client, token);
    if (user->context == UNDEFINED)
        return send_info(server, client, user);
    if (user->context == TEAM)
        return send_team_info(server, client, user);
    if (user->context == CHANNEL)
        return send_channel_info(server, client, user);
    if (user->context == THREAD)
        return send_thread_info(server, client, user);
    return 0;
}
