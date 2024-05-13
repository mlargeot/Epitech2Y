/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** thread_reply
*/

#pragma once

typedef struct thread_reply_entity_s {
    char uuid[37];
    char thread_uuid[37];
    char author_uuid[37];
    char message[512];
} thread_reply_entity_t;

typedef struct thread_reply_dto_s {
    char message[512];
} thread_reply_dto_t;

xml_t *thread_reply_entity_to_xml(thread_reply_entity_t *thread_reply);
