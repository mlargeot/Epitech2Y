/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** ping_controller
*/

#include <router.h>
#include <server/ping.h>

void init_ping_controller(list_t *router)
{
    add_route(router, (route_config_t){"/ping", GET, NULL, get_ping});
}
