/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** use
*/

#include <myteams_server.h>

static int use_team(server_t *server,
    client_t *client, char **cmds, user_t *user)
{
    team_t *team = db_get_team(cmds[1]);

    if (team == NULL)
        return send_team_not_found(server, client, cmds[1]);
    user->context = TEAM;
    user->context_uuid = team->uuid;
    return 0;
}

static int use_channel(server_t *server,
    client_t *client, char **cmds, user_t *user)
{
    team_t *team = db_get_team(cmds[1]);
    channel_t *channel = db_get_channel(cmds[2]);

    if (team == NULL)
        return send_channel_not_found(server, client, cmds[2]);
    if (channel == NULL)
        return send_channel_not_found(server, client, cmds[2]);
    if (channel->team->uuid != team->uuid)
        return send_channel_not_found(server, client, cmds[2]);
    user->context = CHANNEL;
    user->context_uuid = channel->uuid;
    return 0;
}

static int use_thread(server_t *server,
    client_t *client, char **cmds, user_t *user)
{
    team_t *team = db_get_team(cmds[1]);
    channel_t *channel = db_get_channel(cmds[2]);
    thread_t *thread = db_get_thread(cmds[3]);

    if (team == NULL)
        return send_thread_not_found(server, client, cmds[3]);
    if (channel == NULL)
        return send_thread_not_found(server, client, cmds[3]);
    if (thread == NULL)
        return send_thread_not_found(server, client, cmds[3]);
    if (channel->team->uuid != team->uuid)
        return send_thread_not_found(server, client, cmds[3]);
    if (thread->channel->uuid != channel->uuid)
        return send_thread_not_found(server, client, cmds[3]);
    user->context = THREAD;
    user->context_uuid = thread->uuid;
    return 0;
}

int use(server_t *server, client_t *client, char **cmds, char *token)
{
    int nb_args = tab_len((void **)cmds) - 1;
    user_t *user = db_get_user(token);

    if (nb_args == 1)
        return use_team(server, client, cmds, user);
    if (nb_args == 2)
        return use_channel(server, client, cmds, user);
    if (nb_args == 3)
        return use_thread(server, client, cmds, user);
    user->context = UNDEFINED;
    user->context_uuid = NULL;
    return 0;
}
