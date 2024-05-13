/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** thread
*/

#pragma once

typedef struct thread_entity_s {
    char uuid[37];
    char channel_uuid[37];
    char title[32];
    char message[255];
} thread_entity_t;

typedef struct thread_dto_s {
    char channel_uuid[37];
    char title[32];
    char message[255];
} thread_dto_t;

xml_t *thread_entity_to_xml(thread_entity_t *thread);
