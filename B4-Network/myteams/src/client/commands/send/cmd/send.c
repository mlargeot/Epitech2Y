/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** send
*/

#include "client/myteams_cli.h"
#include "xml.h"
#include "response.h"
#include <client/cli_utils.h>
#include <logging_client.h>

static void check_response(response_t *response, char **command)
{
    if (response == NULL)
        return;
    if (response->status_code == CREATED) {
        printf("Message sent\n");
    } else {
        printf("Error: %s\n", response->status_message);
        if (response->status_code == NOT_FOUND)
            client_error_unknown_user(command[1]);
    }
}

void send_message(client_t *client, char **command)
{
    xml_t *xml;
    char *url;
    response_t *response;

    if (get_array_size(command) < 3) {
        printf("Invalid number of arguments\n");
        return;
    }
    xml = xml_new("message");
    if (xml == NULL)
        return;
    xml->root->inner_text = strdup(command[2]);
    asprintf(&url, "/users/messages/%s", command[1]);
    response = fetch_url(client, url, POST, xml_str(xml));
    check_response(response, command);
    xml_free(xml);
    response_free(response);
    free(url);
}
