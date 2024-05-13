/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** messages_controller
*/

#include <router.h>
#include <server/middleware.h>
#include <server/messages.h>

void init_message_controller(list_t *router)
{
    add_route(router, (route_config_t){"/messages/:receiverUuid", GET,
        auth_middleware, get_messages_by_receiver_uuid});
}
