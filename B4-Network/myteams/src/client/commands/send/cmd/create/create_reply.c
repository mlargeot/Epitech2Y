/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create_reply
*/
#include "client/myteams_cli.h"
#include "client/cli_utils.h"
#include "logging_client.h"

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
        client_print_reply_created(uuid, client->cli_uuid, 0,
            xml_get_node_by_tag(xml->root, "message")->inner_text);
        xml_free(xml);
    } else {
        if (response->status_code != CONFLICT)
            client_error_already_exist();
        printf("%d - %s\n", response->status_code, response->status_message);
    }
}

void create_reply(client_t *client, char **command)
{
    xml_t *xml;
    response_t *response;
    char *url;

    if (get_array_size(command) != 2) {
        printf("Invalid number of arguments\n");
        return;
    }
    xml = xml_new("thread_reply");
    if (xml == NULL)
        return;
    xml_new_node(xml->root, "message", strdup(command[1]));
    asprintf(&url, "/threads/%s/reply", client->scope.thread);
    response = fetch_url(client, url, POST, xml_str(xml));
    check_response(client, response);
    free(url);
    xml_free(xml);
    response_free(response);
}
