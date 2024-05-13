/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create
*/

#include <myteams_server.h>

static int create_team(server_t *server, client_t *client,
    char **cmds, user_t *user)
{
    team_t *team = NULL;
    char *response = NULL;

    if (lenstw(cmds) != 3)
        return 0;
    if (is_team_exist(cmds[1]))
        return send_already_exist(server, client, cmds[1]);
    team = db_new_team(cmds[1], cmds[2]);
    asprintf(&response, "400;\"%s\" \"%s\" \"%s\";\n",
        team->uuid, team->name, team->description);
    send(client->sock, response, strlen(response), 0);
    free(response);
    ping_new_team(server, team);
    server_event_team_created(team->uuid, team->name, user->uuid);
    return 0;
}

static int create_channel(server_t *server, client_t *client,
    char **cmds, user_t *user)
{
    team_t *team = db_get_team(user->context_uuid);
    channel_t *channel = NULL;
    char *response = NULL;

    if (lenstw(cmds) != 3)
        return 0;
    if (team == NULL)
        return send_team_not_found(server, client, user->context_uuid);
    if (is_channel_exist(cmds[1], team))
        return send_already_exist(server, client, cmds[1]);
    channel = db_new_channel(cmds[1], cmds[2], team);
    asprintf(&response, "414;\"%s\" \"%s\" \"%s\";\n",
        channel->uuid, channel->name, channel->description);
    send(client->sock, response, strlen(response), 0);
    free(response);
    server_event_channel_created(team->uuid, channel->uuid, channel->name);
    return 0;
}

static int create_thread(server_t *server, client_t *client,
    char **cmds, user_t *user)
{
    channel_t *channel = db_get_channel(user->context_uuid);
    thread_t *thread = NULL;
    char *response = NULL;

    if (lenstw(cmds) != 3)
        return 0;
    if (channel == NULL)
        return send_channel_not_found(server, client, user->context_uuid);
    if (is_thread_exist(cmds[1], channel))
        return send_already_exist(server, client, cmds[1]);
    thread = db_new_thread(cmds[1], cmds[2], channel, user);
    asprintf(&response,
        "430;\"%s\" \"%s\" \"%s\" \"%s\" \"%s\";\n", thread->uuid, user->uuid,
        get_time_str(thread->timestamp), thread->title, thread->message);
    send(client->sock, response, strlen(response), 0);
    free(response);
    server_event_thread_created(channel->uuid,
        thread->uuid, user->uuid, thread->title, thread->message);
    return 0;
}

static int create_reply(server_t *server, client_t *client,
    char **cmds, user_t *user)
{
    thread_t *thread = db_get_thread(user->context_uuid);
    comment_t *reply = NULL;
    char *response = NULL;

    if (lenstw(cmds) != 2)
        return 0;
    if (thread == NULL)
        return send_thread_not_found(server, client, user->context_uuid);
    reply = db_new_comment(cmds[1], user, thread);
    asprintf(&response, "447;\"%s\" \"%s\" \"%s\" \"%s\";\n", reply->uuid,
        user->uuid, get_time_str(reply->timestamp), reply->message);
    send(client->sock, response, strlen(response), 0);
    free(response);
    server_event_reply_created(thread->uuid, user->uuid, reply->message);
    return 0;
}

int create(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(token);

    if (user == NULL)
        return send_user_not_found(server, client, token);
    if (user->context == UNDEFINED)
        return create_team(server, client, cmds, user);
    if (user->context == TEAM)
        return create_channel(server, client, cmds, user);
    if (user->context == CHANNEL)
        return create_thread(server, client, cmds, user);
    if (user->context == THREAD)
        return create_reply(server, client, cmds, user);
    return 0;
}
