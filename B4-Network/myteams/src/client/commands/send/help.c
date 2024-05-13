/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** help
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void help(void)
{
    int fd = open("src/client/commands/send/help.txt", O_RDONLY);
    char buf[2048] = {0};

    if (fd == -1)
        return;
    read(fd, &buf, 2047);
    printf("%s\n", buf);
    close(fd);
}
