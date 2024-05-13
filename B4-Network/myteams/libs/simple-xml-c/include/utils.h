/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** utils
*/

#pragma once

#include <list.h>
#include <stddef.h>

int str_index_of(char *buf, char *value);
char *str_match(char *buf, char *match);
list_t *str_split(char *buf, char *split);
list_t *str_split_list(const char *buf, const int split_length,
    const char **split);
