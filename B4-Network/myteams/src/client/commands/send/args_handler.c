/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** args handler
*/

#include <stdio.h>
#include <string.h>

#include "myteams_cli.h"

bool login_args(char **cmd)
{
    if (strlen(cmd[1]) > MAX_NAME_LENGTH) {
        printf("Invalid name size\n");
        return false;
    }
    return true;
}

bool send_args(char **cmd)
{
    if (strlen(cmd[2]) > MAX_BODY_LENGTH) {
        printf("Invalid body size\n");
        return false;
    }
    return true;
}
