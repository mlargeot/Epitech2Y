/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** utils
*/

#pragma once

#include "method.h"
#include "status_code.h"

method_t string_to_method(const char *method);
void trim_whitespace(char **str);
char *get_status_message(status_code_t status_code);
