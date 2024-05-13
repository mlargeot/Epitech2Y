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

void handle_team_created(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_event_team_created(splited_body[0], splited_body[1],
        splited_body[2]);
    destroy_array(splited_body);
}

void handle_thread_reply(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_event_thread_reply_received(splited_body[0], splited_body[1],
        splited_body[2], splited_body[3]);
    destroy_array(splited_body);
}

void handle_private_message(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_event_private_message_received(splited_body[0], splited_body[1]);
    destroy_array(splited_body);
}

void handle_logged_out(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_event_logged_out(splited_body[0], splited_body[1]);
    destroy_array(splited_body);
}

void handle_logged_in(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_event_logged_in(splited_body[0], splited_body[1]);
    destroy_array(splited_body);
}
