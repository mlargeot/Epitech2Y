/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** utils_str_index_of
*/

#include <stddef.h>

int str_index_of(char *buf, char *value)
{
    int index = 0;
    int start_index = -1;

    if (buf == NULL || value == NULL)
        return -1;
    for (int i = 0; *buf; index++) {
        if (*buf != value[i]) {
            start_index = -1;
            i = 0;
            buf++;
            continue;
        }
        i++;
        if (start_index == -1)
            start_index = index;
        if (value[i] == '\0')
            return start_index;
        buf++;
    }
    return -1;
}
