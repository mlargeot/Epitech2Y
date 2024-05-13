/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** utils
*/

#pragma once

char *extract_bearer_token(char *auth_value);
char *uuid_gen(char *dest);
char *serialize_data(void *elem, size_t size);
char *base64_encode(const unsigned char *data,
    size_t input_length, size_t *output_length);
unsigned char *base64_decode(const char *data,
    size_t input_length, size_t *output_length);
