/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** main
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ftp.h"

int main(int ac, char **av)
{
    if (ac != 3) {
        fprintf(stderr, "Bad argument number.\n");
        return 84;
    } else if (!handle_error(av)) {
        fprintf(stderr, "Bad arguments.\n");
        return 84;
    }
    return start_server(atoi(av[1]));
}
