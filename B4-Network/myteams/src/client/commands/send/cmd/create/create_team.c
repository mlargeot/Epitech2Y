/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create_team
*/

#include "client/myteams_cli.h"
#include "client/cli_utils.h"
#include <logging_client.h>

static void check_response(response_t *response)
{
    xml_t *xml = xml_new(NULL);
    char *uuid;
    char *name;

    if (response == NULL)
        return;
    if (response->status_code == CREATED) {
        xml_parser(xml, response->body);
        uuid = xml_get_node_by_tag(xml->root, "uuid")->inner_text;
        name = xml_get_node_by_tag(xml->root, "name")->inner_text;
        client_event_team_created(uuid, name,
            xml_get_node_by_tag(xml->root, "description")->inner_text);
        client_print_team_created(uuid, name,
            xml_get_node_by_tag(xml->root, "description")->inner_text);
        xml_free(xml);
    } else {
        if (response->status_code != CONFLICT)
            client_error_already_exist();
        printf("%d - %s\n", response->status_code, response->status_message);
    }
}

void create_team(client_t *client, char **command)
{
    xml_t *xml;
    response_t *response;

    if (get_array_size(command) != 3) {
        printf("Invalid number of arguments\n");
        return;
    }
    xml = xml_new("team");
    if (xml == NULL)
        return;
    xml_new_node(xml->root, "name", strdup(command[1]));
    xml_new_node(xml->root, "description", strdup(command[2]));
    response = fetch_url(client, "/teams", POST, xml_str(xml));
    check_response(response);
    xml_free(xml);
    response_free(response);
}
