/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** user_team
*/

#include "db/db.h"

int is_user_in_team(char *user_uuid, char *team_uuid)
{
    user_t *user = db_get_user(user_uuid);

    if (user == NULL)
        return 0;
    for (size_t i = 0; user->teams[i] != NULL; i++) {
        if (strcmp(user->teams[i]->uuid, team_uuid) == 0)
            return 1;
    }
    return 0;
}

int add_user_to_team(char *user_uuid, char *team_uuid)
{
    user_t *user = db_get_user(user_uuid);
    team_t *team = db_get_team(team_uuid);
    size_t len = get_len((void **)user->teams);

    if (user == NULL || team == NULL)
        return 1;
    user->teams = realloc(user->teams, sizeof(team_t *) * (len + 2));
    user->teams[len] = team;
    user->teams[len + 1] = NULL;
    return 0;
}
