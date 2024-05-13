/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create_thread
*/
#include "client/myteams_cli.h"
#include "client/cli_utils.h"
#include <logging_client.h>

static void check_response(client_t *client, response_t *response)
{
    xml_t *xml = xml_new(NULL);
    char *uuid;
    char *title;

    if (response == NULL)
        return;
    if (response->status_code == CREATED) {
        xml_parser(xml, response->body);
        uuid = xml_get_node_by_tag(xml->root, "uuid")->inner_text;
        title = xml_get_node_by_tag(xml->root, "title")->inner_text;
        client_event_thread_created(uuid, client->cli_uuid, 0, title,
            xml_get_node_by_tag(xml->root, "message")->inner_text);
        client_print_thread_created(uuid, client->cli_uuid, 0, title,
            xml_get_node_by_tag(xml->root, "message")->inner_text);
        xml_free(xml);
    } else {
        if (response->status_code != CONFLICT)
            client_error_already_exist();
        printf("%d - %s\n", response->status_code, response->status_message);
    }
}

void create_thread(client_t *client, char **command)
{
    xml_t *xml;
    response_t *response;

    if (get_array_size(command) != 3) {
        printf("Invalid number of arguments\n");
        return;
    }
    xml = xml_new("thread");
    if (xml == NULL)
        return;
    xml_new_node(xml->root, "channel_uuid", strdup(client->scope.channel));
    xml_new_node(xml->root, "title", strdup(command[1]));
    xml_new_node(xml->root, "message", strdup(command[2]));
    response = fetch_url(client, "/threads", POST, xml_str(xml));
    check_response(client, response);
    xml_free(xml);
    response_free(response);
}
