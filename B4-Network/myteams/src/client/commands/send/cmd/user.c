/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** user
*/
#include "client/myteams_cli.h"
#include <client/cli_utils.h>
#include <logging_client.h>

static void check_response(response_t *response, char **command) {
    xml_t *xml = xml_new(NULL);

    if (response == NULL || xml == NULL)
        return;
    if (response->status_code != OK) {
        printf("Error: %s\n", response->status_message);
        if (response->status_code == NOT_FOUND)
            client_error_unknown_user(command[1]);
        return;
    }
    xml_parser(xml, response->body);
}
void user(client_t *client, char **command)
{
    char *url;
    response_t *response;

    if (get_array_size(command) < 2) {
        printf("Invalid number of arguments\n");
        return;
    }
    asprintf(&url, "/users/%s", command[1]);
    response = fetch_url(client, url, GET, NULL);
    check_response(response, command);
    response_free(response);
    free(url);
}