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

void handle_print_channels(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = NULL;

    for (size_t i = 1; serv_resp[i] != NULL; i++) {
        splited_body = mkstw(serv_resp[i]);
        client_team_print_channels(splited_body[0], splited_body[1],
            splited_body[2]);
        destroy_array(splited_body);
        splited_body = NULL;
    }
}

void handle_print_teams(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = NULL;

    for (size_t i = 1; serv_resp[i] != NULL; i++) {
        splited_body = mkstw(serv_resp[i]);
        client_print_teams(splited_body[0], splited_body[1],
            splited_body[2]);
        destroy_array(splited_body);
        splited_body = NULL;
    }
}

void handle_print_users(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = NULL;

    for (size_t i = 1; serv_resp[i] != NULL; i++) {
        splited_body = mkstw(serv_resp[i]);
        client_print_users(splited_body[0], splited_body[1],
            atoi(splited_body[2]));
        destroy_array(splited_body);
        splited_body = NULL;
    }
}

void handle_thread_created(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_event_thread_created(splited_body[0], splited_body[1],
        get_time(splited_body[2]), splited_body[3], splited_body[4]);
    destroy_array(splited_body);
}

void handle_channel_created(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_event_channel_created(splited_body[0], splited_body[1],
        splited_body[2]);
    destroy_array(splited_body);
}
