/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** error handling
*/

#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#include "ftp.h"

static bool handle_path(char *path)
{
    FILE *fp;

    if (chdir(path) == -1)
        return false;
    fp = fopen(path, "r");
    if (fp == NULL)
        return false;
    fclose(fp);
    return true;
}

static bool handle_port(char *port)
{
    int port_int = atoi(port);

    if (port_int < 0 || port_int > 65353)
        return false;
    for (size_t i = 0; port[i] != '\0'; i++) {
        if (port[i] < '0' || port[i] > '9')
            return false;
    }
    return true;
}

bool handle_error(UNUSED char **av)
{
    if (!handle_path(av[2]))
        return false;
    if (!handle_port(av[1]))
        return false;
    return true;
}
