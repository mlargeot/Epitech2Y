/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** ping_service
*/

#include "server.h"

void get_ping(request_t *req UNUSED, response_t *res)
{
    xml_t *node_msg = xml_new("messages");

    node_msg->root->inner_text = strdup("pong");
    new_ok(res, node_msg);
}
