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

void handle_unknown_channel(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_error_unknown_channel(splited_body[0]);
    destroy_array(splited_body);
}

void handle_unknown_team(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_error_unknown_team(splited_body[0]);
    destroy_array(splited_body);
}

void handle_pv_mess_print_mess(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = NULL;

    for (size_t i = 1; serv_resp[i] != NULL; i++) {
        splited_body = mkstw(serv_resp[i]);
        client_private_message_print_messages(splited_body[0],
            get_time(splited_body[1]), splited_body[2]);
        destroy_array(splited_body);
        splited_body = NULL;
    }
}

void handle_thread_print_replies(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = NULL;

    for (size_t i = 1; serv_resp[i] != NULL; i++) {
        splited_body = mkstw(serv_resp[i]);
        client_thread_print_replies(splited_body[0], splited_body[1],
            get_time(splited_body[2]), splited_body[3]);
        destroy_array(splited_body);
        splited_body = NULL;
    }
}

void handle_print_threads(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = NULL;

    for (size_t i = 1; serv_resp[i] != NULL; i++) {
        splited_body = mkstw(serv_resp[i]);
        client_channel_print_threads(splited_body[0], splited_body[1],
            get_time(splited_body[2]), splited_body[3], splited_body[4]);
        destroy_array(splited_body);
        splited_body = NULL;
    }
}
