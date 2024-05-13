/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** create_team
*/
#include "request.h"
#include "response.h"
#include <server/teams.h>
#include <server/utils.h>
#include <logging_server.h>

team_dto_t *team_dto_new(xml_t *body)
{
    team_dto_t *team = calloc(1, sizeof(team_dto_t));

    if (team == NULL)
        return NULL;
    strcpy(team->name, xml_get_node_by_tag(body->root, "name")->inner_text);
    strcpy(team->description,
        xml_get_node_by_tag(body->root, "description")->inner_text);
    return team;
}

team_entity_t *team_entity_new(team_dto_t *data)
{
    team_entity_t *team = calloc(1, sizeof(team_entity_t));

    if (team == NULL)
        return NULL;
    strcpy(team->name, data->name);
    strcpy(team->description, data->description);
    uuid_gen(team->uuid);
    return team;
}

team_entity_t *get_team_by_name(map_t *teams, char *name)
{
    team_entity_t *team;

    for (map_node_t *node = teams->head; node; node = node->next) {
        team = node->value;
        if (strcmp(team->name, name) == 0)
            return team;
    }
    return NULL;
}

bool check_dto(team_dto_t *dto, response_t *res)
{
    if (dto == NULL) {
        new_bad_request(res, "Invalid body");
        return false;
    }
    if (strlen(dto->name) > 32) {
        new_bad_request(res, "Name too long");
        return false;
    }
    if (strlen(dto->description) > 255) {
        new_bad_request(res, "Description too long");
        return false;
    }
    return true;
}

void create_team(request_t *req, response_t *res)
{
    team_dto_t *data = team_dto_new(req->body);
    team_entity_t *team;
    map_node_t *teams = map_get(req->cache, "teams");
    char *auth = map_get(req->headers, "Authorization")->value;
    char *token = extract_bearer_token(auth);

    if (!check_dto(data, res)) {
        free(data);
        return;
    }
    team = team_entity_new(data);
    if (get_team_by_name(teams->value, team->name)) {
        new_conflict(res, "Team already exists");
        return;
    }
    map_add(teams->value, team->uuid, team);
    server_event_team_created(team->uuid, team->name, token);
    new_created(res, team_entity_to_xml(team));
    free(data);
    free(token);
}
