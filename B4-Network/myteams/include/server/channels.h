/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** channels
*/

#pragma once

#include <router.h>

void init_channels_controller(list_t *router);
void create_channel(request_t *req, response_t *res);
void get_channels(request_t *req, response_t *res);
void get_channel_by_uuid(request_t *req, response_t *res);
