/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** header file
*/

#ifndef FTP_H_
    #define FTP_H_

    #include <stdbool.h>

    #define UNUSED __attribute__((unused))

//ERROR HANDLING
bool handle_error(UNUSED char **av);

//SERVER
int start_server(int port);

#endif /* !FTP_H_ */
