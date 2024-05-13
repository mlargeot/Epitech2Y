/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** init_db
*/

#include "db/db.h"

static int init_list(void ***list, size_t size)
{
    *list = malloc(size);
    if (*list == NULL)
        return (1);
    *list[0] = NULL;
    return (0);
}

int init_db(void)
{
    db_t *db = malloc(sizeof(db_t));

    if (db == NULL)
        return (1);
    if (init_list((void ***)&db->teams, sizeof(team_t *) * 1) ||
    init_list((void ***)&db->channels, sizeof(channel_t *) * 1) ||
    init_list((void ***)&db->threads, sizeof(thread_t *) * 1) ||
    init_list((void ***)&db->users, sizeof(user_t *) * 1) ||
    init_list((void ***)&db->messages, sizeof(message_t *) * 1) ||
    init_list((void ***)&db->comments, sizeof(comment_t *) * 1))
        return (1);
    get_set_db(db);
    return (0);
}
