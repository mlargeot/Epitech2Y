/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** teams
*/

#pragma once

#include <router.h>
#include <share/team.h>

void init_teams_controller(list_t *router);
void create_team(request_t *req, response_t *res);
void get_teams(request_t *req, response_t *res);
void get_team_by_uuid(request_t *req, response_t *res);
void subscribe_team(request_t *req, response_t *res);
void unsubscribe_team(request_t *req, response_t *res);
xml_t *team_entity_to_xml(team_entity_t *team);
