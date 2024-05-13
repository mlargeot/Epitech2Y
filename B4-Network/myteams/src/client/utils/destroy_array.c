/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** destroy array
*/

#include <stdlib.h>
#include <stddef.h>

void destroy_array(char **array)
{
    size_t i = 0;

    for (; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
