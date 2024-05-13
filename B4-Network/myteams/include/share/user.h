/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** user
*/

#pragma once

#include "xml.h"

typedef struct user_entity_s {
    char uuid[37];
    char username[32];
} user_entity_t;

typedef struct user_dto_s {
    char username[32];
} user_dto_t;

xml_t *user_entity_to_xml(user_entity_t *user);
