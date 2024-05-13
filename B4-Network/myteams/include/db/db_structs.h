/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** db_structs
*/

#ifndef DB_STRUCTS_H_
    #define DB_STRUCTS_H_

    #include <time.h>

typedef enum context_e {
    TEAM,
    CHANNEL,
    THREAD,
    UNDEFINED
} context_t;

typedef struct team_s {
    char *uuid;
    char *name;
    char *description;
} team_t;

typedef struct channel_s {
    char *uuid;
    char *name;
    char *description;
    team_t *team;
} channel_t;

typedef struct user_s {
    char *uuid;
    char *username;
    char *password;
    team_t **teams;
    context_t context;
    char *context_uuid;
    int is_logged;
} user_t;

typedef struct thread_s {
    char *uuid;
    char *title;
    char *message;
    time_t timestamp;
    user_t *user;
    channel_t *channel;
} thread_t;

typedef struct comment_s {
    char *uuid;
    char *message;
    user_t *user;
    thread_t *thread;
    time_t timestamp;
} comment_t;

typedef struct message_s {
    char *uuid;
    char *message;
    user_t *sender;
    user_t *receiver;
    time_t timestamp;
} message_t;

typedef struct db_s {
    char *path;

    team_t **teams;
    channel_t **channels;
    thread_t **threads;
    user_t **users;
    comment_t **comments;
    message_t **messages;
} db_t;

#endif /* !DB_STRUCTS_H_ */
