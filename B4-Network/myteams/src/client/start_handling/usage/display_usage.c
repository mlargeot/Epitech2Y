/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** display_usage
*/

#include <stdio.h>

int display_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("        ip    is the server ip address "
    "on which the server socket listens\n");
    printf("        port  is the port number on which the "
    "server socket listens\n");
    return 0;
}
