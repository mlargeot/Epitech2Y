/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** free_db
*/

#include "db/db.h"

void safe_free(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
}

int free_db(db_t *db)
{
    if (db == NULL)
        return 1;
    free_teams(db->teams);
    free_channels(db->channels);
    free_threads(db->threads);
    free_users(db->users);
    free_messages(db->messages);
    free_comments(db->comments);
    safe_free(db);
    return 0;
}
