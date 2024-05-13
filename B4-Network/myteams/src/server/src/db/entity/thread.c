/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-mythreads-morgan.largeot
** File description:
** thread
*/

#include "db/db.h"

int free_threads(thread_t **threads)
{
    if (threads == NULL)
        return 1;
    for (size_t i = 0; threads[i] != NULL; i++) {
        safe_free(threads[i]->uuid);
        safe_free(threads[i]);
    }
    safe_free(threads);
    return 0;
}

thread_t **db_get_threads(void)
{
    db_t *db = get_set_db(NULL);

    return db->threads;
}

thread_t *db_new_thread(char *title, char *message,
    channel_t *channel, user_t *user)
{
    db_t *db = get_set_db(NULL);
    thread_t *new_thread = malloc(sizeof(thread_t));
    size_t len = get_len((void **)db->threads);

    if (new_thread == NULL)
        return NULL;
    new_thread->uuid = uuid_gen(NULL);
    new_thread->title = strdup(title);
    new_thread->message = strdup(message);
    new_thread->channel = channel;
    new_thread->timestamp = time(NULL);
    new_thread->user = user;
    db->threads = realloc(db->threads, sizeof(thread_t *) * (len + 2));
    db->threads[len] = new_thread;
    db->threads[len + 1] = NULL;
    return new_thread;
}

int save_threads(FILE *file, thread_t **threads)
{
    size_t len = get_len((void **)threads);

    fwrite(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        fwrite_str(file, threads[i]->uuid);
        fwrite_str(file, threads[i]->title);
        fwrite_str(file, threads[i]->message);
        fwrite_str(file, threads[i]->channel->uuid);
        fwrite_str(file, threads[i]->user->uuid);
        fwrite(&threads[i]->timestamp, sizeof(time_t), 1, file);
    }
    return 0;
}

int load_threads(FILE *file, db_t *db)
{
    size_t len = 0;
    thread_t *new_thread = NULL;

    fread(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        new_thread = malloc(sizeof(thread_t));
        if (new_thread == NULL)
            return 1;
        new_thread->uuid = fread_str(file);
        new_thread->title = fread_str(file);
        new_thread->message = fread_str(file);
        new_thread->channel = db_get_channel(fread_str(file));
        new_thread->user = db_get_user(fread_str(file));
        fread(&new_thread->timestamp, sizeof(time_t), 1, file);
        db->threads = realloc(db->threads, sizeof(thread_t *) * (i + 2));
        db->threads[i] = new_thread;
        db->threads[i + 1] = NULL;
    }
    return 0;
}
