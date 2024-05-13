/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-mycomments-morgan.largeot
** File description:
** comment
*/

#include "db/db.h"

int free_comments(comment_t **comments)
{
    if (comments == NULL)
        return 1;
    for (size_t i = 0; comments[i] != NULL; i++) {
        safe_free(comments[i]->uuid);
        safe_free(comments[i]);
    }
    safe_free(comments);
    return 0;
}

comment_t **db_get_comments(void)
{
    db_t *db = get_set_db(NULL);

    return db->comments;
}

comment_t *db_new_comment(char *message, user_t *user, thread_t *thread)
{
    db_t *db = get_set_db(NULL);
    comment_t *new_comment = malloc(sizeof(comment_t));
    size_t len = get_len((void **)db->comments);

    if (new_comment == NULL)
        return NULL;
    new_comment->uuid = uuid_gen(NULL);
    new_comment->message = strdup(message);
    new_comment->user = user;
    new_comment->thread = thread;
    new_comment->timestamp = time(NULL);
    db->comments = realloc(db->comments, sizeof(comment_t *) * (len + 2));
    db->comments[len] = new_comment;
    db->comments[len + 1] = NULL;
    return new_comment;
}

int save_comments(FILE *file, comment_t **comments)
{
    size_t len = get_len((void **)comments);

    fwrite(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        fwrite_str(file, comments[i]->uuid);
        fwrite_str(file, comments[i]->message);
        fwrite_str(file, comments[i]->user->uuid);
        fwrite_str(file, comments[i]->thread->uuid);
        fwrite(&comments[i]->timestamp, sizeof(time_t), 1, file);
    }
    return 0;
}

int load_comments(FILE *file, db_t *db)
{
    size_t len = 0;
    comment_t *new_comment = NULL;

    fread(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        new_comment = malloc(sizeof(comment_t));
        if (new_comment == NULL)
            return 1;
        new_comment->uuid = fread_str(file);
        new_comment->message = fread_str(file);
        new_comment->user = db_get_user(fread_str(file));
        new_comment->thread = db_get_thread(fread_str(file));
        fread(&new_comment->timestamp, sizeof(time_t), 1, file);
        db->comments = realloc(db->comments, sizeof(comment_t *) * (i + 2));
        db->comments[i] = new_comment;
        db->comments[i + 1] = NULL;
    }
    return 0;
}
