/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** channel
*/

#pragma once

#include <request.h>
#include <response.h>

typedef struct channel_entity_s {
    char uuid[37];
    char team_uuid[37];
    char name[32];
    char description[255];
} channel_entity_t;

typedef struct channel_dto_s {
    char team_uuid[37];
    char name[32];
    char description[255];
} channel_dto_t;

xml_t *channel_entity_to_xml(channel_entity_t *channel);
