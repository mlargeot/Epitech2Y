/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** get_comments
*/

#include "db/db.h"

comment_t **db_get_comments_from_thread(char *uuid)
{
    db_t *db = get_set_db(NULL);
    comment_t **comments = NULL;
    size_t len = 0;

    for (size_t i = 0; db->comments[i] != NULL; i++) {
        if (strcmp(db->comments[i]->thread->uuid, uuid) == 0) {
            comments = realloc(comments, sizeof(comment_t *) * (len + 2));
            comments[len] = db->comments[i];
            comments[len + 1] = NULL;
            len++;
        }
    }
    return comments;
}

comment_t **db_get_comments_from_user(char *uuid)
{
    db_t *db = get_set_db(NULL);
    comment_t **comments = NULL;
    size_t len = 0;

    for (size_t i = 0; db->comments[i] != NULL; i++) {
        if (strcmp(db->comments[i]->user->uuid, uuid) == 0) {
            comments = realloc(comments, sizeof(comment_t *) * (len + 2));
            comments[len] = db->comments[i];
            comments[len + 1] = NULL;
            len++;
        }
    }
    return comments;
}
