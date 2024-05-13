/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** main
*/

#include <server/messages.h>
#include <server/channels.h>
#include <server/threads.h>
#include <server/teams.h>
#include <server/users.h>
#include <server/auth.h>
#include <server/ping.h>
#include <server.h>
#include <stdio.h>
#include <db/db.h>
#include <signal.h>
#include <string.h>

int usage(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\tport is the port number on which the server socket listens.\n");
    return 0;
}

void init_router_controller(list_t *router)
{
    init_users_controller(router);
    init_teams_controller(router);
    init_message_controller(router);
    init_channels_controller(router);
    init_threads_controller(router);
    init_auth_controller(router);
    init_ping_controller(router);
}

void init_cache(map_t *cache)
{
    map_add(cache, "users", list_new());
    map_add(cache, "teams", map_new());
    map_add(cache, "messages", list_new());
    map_add(cache, "channels", map_new());
    map_add(cache, "threads", map_new());
    map_add(cache, "threads_replays", map_new());
}

static void save_db_on_signal(int sig)
{
    save_db("db.txt");
    exit(0);
}

static void set_signal(void)
{
    signal(SIGINT, save_db_on_signal);
    signal(SIGTERM, save_db_on_signal);
}

int main(int ac, char **av)
{
    list_t *router = list_new();
    map_t *cache = map_new();

    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return (usage());
    init_db();
    load_db("db.txt");
    set_signal();
    init_cache(cache);
    init_router_controller(router);
    start_server(8080, router, cache);
    save_db("db.txt");
    return 0;
}
