/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** string_to_method
*/

#include <string.h>
#include <method.h>

method_t string_to_method(const char *method)
{
    for (int i = 0; methods[i].string != NULL; i++) {
        if (strcmp(methods[i].string, method) == 0)
            return methods[i].method;
    }
    return INVALID_METHOD;
}
