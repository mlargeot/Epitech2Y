/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** messages
*/

#pragma once

#include <router.h>

void init_message_controller(list_t *router);
void get_messages_by_receiver_uuid(request_t *req, response_t *res);
