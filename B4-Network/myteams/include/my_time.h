/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** my_time
*/

#ifndef MY_TIME_H_
    #define MY_TIME_H_

    #include <time.h>
    #define TIME_SIZE 20

time_t get_time(char *time_str);
char *get_time_str(time_t time);

#endif /* !MY_TIME_H_ */
