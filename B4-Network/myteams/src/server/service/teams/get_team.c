/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_team
*/
#include "request.h"
#include "response.h"
#include <server/teams.h>
#include <stdio.h>

void get_teams(request_t *req, response_t *res)
{
    map_t *teams = map_get(req->cache, "teams")->value;
    xml_t *data = xml_new("teams");

    for (map_node_t *node = teams->head; node; node = node->next)
        xml_add_node(data->root, team_entity_to_xml(node->value)->root);
    new_ok(res, data);
}

void get_team_by_uuid(request_t *req, response_t *res)
{
    map_node_t *uuid_node = map_get(req->params, "teamUuid");
    map_t *teams = map_get(req->cache, "teams")->value;
    map_node_t *team;

    if (uuid_node == NULL) {
        new_bad_request(res, "Invalid pram");
        return;
    }
    team = map_get(teams, uuid_node->value);
    if (team == NULL) {
        new_not_found(res, "Team not found");
        return;
    }
    new_ok(res, team_entity_to_xml(team->value));
}
