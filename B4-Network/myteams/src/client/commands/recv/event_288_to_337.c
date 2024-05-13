/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** event handling
*/

#include <stdlib.h>
#include <string.h>

#include "logging_client.h"
#include "myteams_cli.h"

void handle_print_user(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_user(splited_body[0], splited_body[1],
        atoi(splited_body[2]));
    destroy_array(splited_body);
}

void handle_already_exist(UNUSED client_t *client, UNUSED char **serv_resp)
{
    client_error_already_exist();
}

void handle_unauthorized(UNUSED client_t *client, UNUSED char **serv_resp)
{
    client_error_unauthorized();
}

void handle_unknown_user(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_error_unknown_user(splited_body[0]);
    destroy_array(splited_body);
}

void handle_unknown_thread(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_error_unknown_thread(splited_body[0]);
    destroy_array(splited_body);
}
