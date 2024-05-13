/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-mymessages-morgan.largeot
** File description:
** message
*/

#include "db/db.h"

int free_messages(message_t **messages)
{
    if (messages == NULL)
        return 1;
    for (size_t i = 0; messages[i] != NULL; i++) {
        safe_free(messages[i]->uuid);
        safe_free(messages[i]);
    }
    safe_free(messages);
    return 0;
}

message_t **db_get_messages(void)
{
    db_t *db = get_set_db(NULL);

    return db->messages;
}

message_t *db_new_message(char *message, user_t *sender, user_t *receiver)
{
    db_t *db = get_set_db(NULL);
    message_t *new_message = malloc(sizeof(message_t));
    size_t len = get_len((void **)db->messages);

    if (new_message == NULL)
        return NULL;
    new_message->uuid = uuid_gen(NULL);
    new_message->message = strdup(message);
    new_message->sender = sender;
    new_message->receiver = receiver;
    new_message->timestamp = time(NULL);
    db->messages = realloc(db->messages, sizeof(message_t *) * (len + 2));
    db->messages[len] = new_message;
    db->messages[len + 1] = NULL;
    return new_message;
}

int save_messages(FILE *file, message_t **messages)
{
    size_t len = get_len((void **)messages);

    fwrite(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        fwrite_str(file, messages[i]->uuid);
        fwrite_str(file, messages[i]->message);
        fwrite_str(file, messages[i]->sender->uuid);
        fwrite_str(file, messages[i]->receiver->uuid);
        fwrite(&messages[i]->timestamp, sizeof(time_t), 1, file);
    }
    return 0;
}

int load_messages(FILE *file, db_t *db)
{
    size_t len = 0;
    message_t *new_message = NULL;

    fread(&len, sizeof(size_t), 1, file);
    for (size_t i = 0; i < len; i++) {
        new_message = malloc(sizeof(message_t));
        if (new_message == NULL)
            return 1;
        new_message->uuid = fread_str(file);
        new_message->message = fread_str(file);
        new_message->sender = db_get_user(fread_str(file));
        new_message->receiver = db_get_user(fread_str(file));
        fread(&new_message->timestamp, sizeof(time_t), 1, file);
        db->messages = realloc(db->messages, sizeof(message_t *) * (i + 2));
        db->messages[i] = new_message;
        db->messages[i + 1] = NULL;
    }
    return 0;
}
