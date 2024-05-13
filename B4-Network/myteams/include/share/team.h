/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** team
*/

#pragma once

#include <uuid/uuid.h>
#include <type.h>

typedef struct team_entity_s {
    char uuid[37];
    char name[32];
    char description[255];
} team_entity_t;

typedef struct team_dto_s {
    char name[32];
    char description[255];
} team_dto_t;
