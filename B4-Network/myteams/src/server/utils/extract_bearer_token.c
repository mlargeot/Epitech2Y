/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** extract_bearer_token
*/

#include <string.h>

char *extract_bearer_token(char *auth_value)
{
    const char *prefix = "Bearer ";
    size_t prefix_len = strlen(prefix);

    if (strncmp(auth_value, prefix, prefix_len) == 0)
        return strdup(auth_value + prefix_len);
    return NULL;
}
