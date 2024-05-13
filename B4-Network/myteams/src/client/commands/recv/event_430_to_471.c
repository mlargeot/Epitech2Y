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

void handle_print_unsubscribed(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_unsubscribed(splited_body[0], splited_body[1]);
    destroy_array(splited_body);
}

void handle_print_subscribed(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_subscribed(splited_body[0], splited_body[1]);
    destroy_array(splited_body);
}

void handle_print_reply_created(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_reply_created(splited_body[0], splited_body[1],
        get_time(splited_body[2]), splited_body[3]);
    destroy_array(splited_body);
}

void handle_print_thread_created(UNUSED client_t *client, char **serv_resp)
{
    char **splited_body = mkstw(serv_resp[1]);

    client_print_thread_created(splited_body[0], splited_body[1],
        get_time(splited_body[2]), splited_body[3], splited_body[4]);
    destroy_array(splited_body);
}
