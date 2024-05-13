/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** teams_controller
*/

#include <router.h>
#include <server/middleware.h>
#include <server/teams.h>

void init_teams_controller(list_t *router)
{
    add_route(router, (route_config_t){"/teams", POST,
        auth_middleware, create_team});
    add_route(router, (route_config_t){"/teams/:teamUuid/subscribe", POST,
        auth_middleware, NULL});
    add_route(router, (route_config_t){"/teams/:teamUuid/unsubscribed",
        POST, auth_middleware, NULL});
    add_route(router, (route_config_t){"/teams", GET,
        auth_middleware, get_teams});
    add_route(router, (route_config_t){"/teams/:teamUuid", GET,
        auth_middleware, get_team_by_uuid});
}
