/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** error handling
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "myteams_cli.h"

static bool handle_ip(char *ip)
{
    char **splited_ip = split_string(ip, ".");
    int ip_nb[4] = {-1};
    size_t i = 0;

    while (splited_ip[i] != NULL)
        i++;
    if (i != 4 || sscanf(ip, "%d.%d.%d.%d", &ip_nb[0], &ip_nb[1], &ip_nb[2],
        &ip_nb[3]) == EOF) {
        destroy_array(splited_ip);
        return false;
    }
    for (i = 0; i < 4; i++) {
        if (ip_nb[i] == -1) {
            destroy_array(splited_ip);
            return false;
        }
    }
    destroy_array(splited_ip);
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

bool handle_error(char **av)
{
    if (!handle_ip(av[1]))
        return false;
    if (!handle_port(av[2]))
        return false;
    return true;
}
