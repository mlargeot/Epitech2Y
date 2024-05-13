/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** save_db
*/

#include "db/db.h"

size_t get_len(void **ptr)
{
    size_t len = 0;

    if (ptr == NULL)
        return 0;
    for (size_t i = 0; ptr[i] != NULL; i++)
        len++;
    return len;
}

int fwrite_str(FILE *file, char *str)
{
    size_t tmp = 0;

    tmp = strlen(str);
    fwrite(&tmp, sizeof(size_t), 1, file);
    fwrite(str, sizeof(char), tmp, file);
    return 0;
}

int save_db(char *path)
{
    FILE *file = fopen(path, "w");
    db_t *db = get_set_db(NULL);

    if (file == NULL)
        return (1);
    save_teams(file, db->teams);
    save_channels(file, db->channels);
    save_threads(file, db->threads);
    save_users(file, db->users);
    save_comments(file, db->comments);
    save_messages(file, db->messages);
    fclose(file);
    return (0);
}
