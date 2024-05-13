/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** users_controller
*/

#include <router.h>
#include <server/middleware.h>
#include <server/users.h>

void init_users_controller(list_t *router)
{
    add_route(router, (route_config_t){"/users/messages/:receiverUuid",
        POST, auth_middleware, send_message_to_user});
    add_route(router, (route_config_t){"/users", GET,
        auth_middleware, get_users});
    add_route(router, (route_config_t){"/users/:userUuid", GET,
        auth_middleware, get_user_by_uuid});
}
