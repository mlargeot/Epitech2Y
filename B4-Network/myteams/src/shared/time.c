/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** time
*/

#include <time_include.h>

char *get_time_str(time_t time)
{
    char *str = calloc(TIME_SIZE, sizeof(char));
    struct tm *tm_info;

    tm_info = localtime(&time);
    strftime(str, 20, "%Y-%m-%d %H:%M:%S", tm_info);
    return str;
}

time_t get_time(char *time_str)
{
    struct tm tm = {0};

    strptime(time_str, "%Y-%m-%d %H:%M:%S", &tm);
    return mktime(&tm);
}
