/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** db_methods
*/

#ifndef DB_METHODS_H_
    #define DB_METHODS_H_

    #include "db_structs.h"
    #include "db_interfaces.h"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

int init_db(void);
int save_db(char *path);
int load_db(char *path);

void safe_free(void *ptr);
int free_db(db_t *db);
size_t get_len(void **list);
int fwrite_str(FILE *file, char *str);
char *fread_str(FILE *file);
void display_db(void);

int free_channels(channel_t **channels);
int free_comments(comment_t **comments);
int free_messages(message_t **messages);
int free_teams(team_t **teams);
int free_threads(thread_t **threads);
int free_users(user_t **users);

int db_new_channel(char *name, char *description, team_t *team);
int db_new_comment(char *message, user_t *user, thread_t *thread);
int db_new_message(char *message, user_t *sender, user_t *receiver);
int db_new_team(char *name, char *description);
int db_new_thread(char *title, char *message, channel_t *channel);
int db_new_user(char *username, char *password);

int db_delete_channel(char *uuid);
int db_delete_comment(char *uuid);
int db_delete_team(char *uuid);
int db_delete_message(char *uuid);
int db_delete_thread(char *uuid);
int db_delete_user(char *uuid);

int save_channels(FILE *file, channel_t **channels);
int save_teams(FILE *file, team_t **teams);
int save_threads(FILE *file, thread_t **threads);
int save_users(FILE *file, user_t **users);
int save_comments(FILE *file, comment_t **comments);
int save_messages(FILE *file, message_t **messages);

int load_teams(FILE *file, db_t *db);
int load_channels(FILE *file, db_t *db);
int load_threads(FILE *file, db_t *db);
int load_users(FILE *file, db_t *db);
int load_comments(FILE *file, db_t *db);
int load_messages(FILE *file, db_t *db);

team_t *db_get_team(char *uuid);
channel_t *db_get_channel(char *uuid);
thread_t *db_get_thread(char *uuid);
user_t *db_get_user(char *uuid);
comment_t *db_get_comment(char *uuid);
message_t *db_get_message(char *uuid);

team_t **db_get_teams(void);
channel_t **db_get_channels(void);
thread_t **db_get_threads(void);
user_t **db_get_users(void);
comment_t **db_get_comments(void);
message_t **db_get_messages(void);

message_t **db_get_messages_from_user(char *uuid);
message_t **db_get_messages_user_to_user(char *uuid_sender,
    char *uuid_receiver);

comment_t **db_get_comments_from_thread(char *uuid);
comment_t **db_get_comments_from_user(char *uuid);

channel_t **get_channels_from_team(char *uuid);
thread_t **get_threads_from_channel(char *uuid);
user_t **get_users_from_team(char *uuid);

int add_user_to_team(char *user_uuid, char *team_uuid);
int is_user_in_team(char *user_uuid, char *team_uuid);

#endif /* !DB_METHODS_H_ */
