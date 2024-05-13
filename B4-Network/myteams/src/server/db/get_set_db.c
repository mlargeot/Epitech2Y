/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_set_db
*/

#include "db/db.h"

db_t *get_set_db(db_t *db)
{
    static db_t *static_db = NULL;

    if (db == NULL)
        return static_db;
    if (static_db != db) {
        free_db(static_db);
        static_db = db;
    }
    return static_db;
}
