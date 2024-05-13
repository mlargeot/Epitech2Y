/*
** EPITECH PROJECT, 2024
** my_teams
** File description:
** get_array_size
*/

#include <stddef.h>

size_t get_array_size(char **array)
{
    size_t size = 0;

    if (array == NULL)
        return size;
    for (; array[size] != NULL; size++);
    return size;
}
