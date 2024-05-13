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
#include "my_time.h"

void handle_print_channel_created(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_channel_created(splited_body[0], splited_body[1],
        splited_body[2]);
    destroy_array(splited_body);
}

void handle_print_team_created(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_team_created(splited_body[0], splited_body[1],
        splited_body[2]);
    destroy_array(splited_body);
}

void handle_print_thread(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_thread(splited_body[0], splited_body[1],
        get_time(splited_body[2]), splited_body[3], splited_body[4]);
    destroy_array(splited_body);
}

void handle_print_channel(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_channel(splited_body[0], splited_body[1],
        splited_body[2]);
    destroy_array(splited_body);
}

void handle_print_team(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_team(splited_body[0], splited_body[1],
        splited_body[2]);
    destroy_array(splited_body);
}
