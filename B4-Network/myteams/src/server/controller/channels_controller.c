/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** channels_controller
*/

#include <router.h>
#include <server/middleware.h>
#include <server/channels.h>

void init_channels_controller(list_t *router)
{
    add_route(router, (route_config_t){"/channels", POST,
        auth_middleware, create_channel});
    add_route(router, (route_config_t){"/channels", GET,
        auth_middleware, get_channels});
    add_route(router, (route_config_t){"/channels/:channelUuid", GET,
        auth_middleware, get_channel_by_uuid});
}
