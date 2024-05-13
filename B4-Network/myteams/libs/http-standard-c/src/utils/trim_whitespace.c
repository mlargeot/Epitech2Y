/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** trim_whitespace
*/

#include <string.h>
#include "ctype.h"

void trim_whitespace(char **str)
{
    char *s = *str;
    char *end;

    while (isspace((unsigned char)*s))
        s++;
    *str = s;
    end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }
}
