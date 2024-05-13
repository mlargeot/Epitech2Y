/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** status_code_to_string
*/

#include <status_code.h>
#include <stddef.h>

char *get_status_message(status_code_t status_code)
{
    for (const status_code_info_t *info = status_codes;
        info->message != NULL; info++)
        if (info->code == status_code)
            return (char *)info->message;
    return "Unknown";
}
