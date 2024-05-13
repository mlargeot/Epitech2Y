/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** threads
*/

#pragma once

#include <router.h>

void init_threads_controller(list_t *router);
void create_thread(request_t *req, response_t *res);
void get_threads(request_t *req, response_t *res);
void get_thread_by_uuid(request_t *req, response_t *res);
void reply_thread(request_t *req, response_t *res);
void get_thread_replays(request_t *req, response_t *res);
