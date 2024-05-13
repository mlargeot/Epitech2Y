/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** threads_controller
*/

#include <router.h>
#include <server/middleware.h>
#include <server/threads.h>

void init_threads_controller(list_t *router)
{
    add_route(router, (route_config_t){"/threads", POST,
        auth_middleware, create_thread});
    add_route(router, (route_config_t){"/threads/:threadUuid/reply",
        POST, auth_middleware, reply_thread});
    add_route(router, (route_config_t){"/threads/:threadUuid/replays", GET,
        auth_middleware, get_thread_replays});
    add_route(router, (route_config_t){"/threads", GET,
        auth_middleware, get_threads});
    add_route(router, (route_config_t){"/threads/:threadUuid",
        GET, auth_middleware, get_thread_by_uuid});
}
