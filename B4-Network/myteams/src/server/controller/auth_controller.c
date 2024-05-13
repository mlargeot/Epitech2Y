/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** auth_controller
*/

#include <router.h>
#include <server/middleware.h>
#include <server/auth.h>

void init_auth_controller(list_t *router)
{
    add_route(router, (route_config_t){"/auth/login", POST,
        NULL, login_auth});
    add_route(router, (route_config_t){"/auth/logout", POST,
        auth_middleware, logout_auth});
}
