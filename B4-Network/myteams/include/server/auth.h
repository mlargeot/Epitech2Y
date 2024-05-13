/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** auth
*/

#pragma once

#include <router.h>

void init_auth_controller(list_t *router);
void login_auth(request_t *req, response_t *res);
void logout_auth(request_t *req, response_t *res);
