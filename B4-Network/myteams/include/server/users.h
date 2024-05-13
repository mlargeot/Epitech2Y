/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** users
*/

#pragma once
#include <router.h>

void init_users_controller(list_t *router);
void get_users(request_t *req, response_t *res);
void get_user_by_uuid(request_t *req, response_t *res);
void send_message_to_user(request_t *req, response_t *res);
