/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** message
*/

#pragma once

#include <time.h>

typedef struct message_entity_s {
    char uuid[37];
    char sender_uuid[37];
    char receiver_uuid[37];
    char message[512];
    time_t created_at;
} message_entity_t;

typedef struct message_dto_s {
    char receiver_uuid[37];
    char message[512];
} message_dto_t;

xml_t *message_entity_to_xml(message_entity_t *message);
