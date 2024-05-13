/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** load_db
*/

#include "db/db.h"

char *fread_str(FILE *file)
{
    size_t len = 0;
    char *str = NULL;

    fread(&len, sizeof(size_t), 1, file);
    str = calloc(len + 1, sizeof(char));
    fread(str, sizeof(char), len, file);
    return str;
}

int load_db(char *path)
{
    FILE *file = fopen(path, "r");
    db_t *db = get_set_db(NULL);

    if (file == NULL)
        return 1;
    load_teams(file, db);
    load_channels(file, db);
    load_threads(file, db);
    load_users(file, db);
    load_comments(file, db);
    load_messages(file, db);
    fclose(file);
    return 0;
}
