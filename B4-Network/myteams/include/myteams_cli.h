/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** include
*/

#ifndef _MYTEAMS_CLI_H__
    #define _MYTEAMS_CLI_H__

    #define UNUSED __attribute__((unused))

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    #define _GNU_SOURCE
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <sys/select.h>
    #include <stddef.h>

typedef struct client_struct {
    char *cli_uuid;
    char *username;
    int cli_fd;
    struct sockaddr_in cli_adr;
    socklen_t adr_len;

    char *server_buffer;
} client_t;

typedef struct fp_s {
    char *command;
    size_t nb_min_args;
    size_t nb_max_args;
    bool (*handler)(char **);
} fp_t;

// ARGS LENGTH HANDLING
bool login_args(char **cmd);
bool send_args(char **cmd);

static fp_t cmds[] __attribute__((unused)) = {
    {"/help", 0, 0, NULL},
    {"/login", 1, 1, login_args},
    {"/logout", 0, 0, NULL},
    {"/users", 0, 0, NULL},
    {"/user", 1, 1, NULL},
    {"/send", 2, 2, send_args},
    {"/messages", 1, 1, NULL},
    {"/subscribe", 1, 1, NULL},
    {"/subscribed", 0, 1, NULL},
    {"/unsubscribe", 1, 1, NULL},
    {"/use", 0, 3, NULL},
    {"/create", 1, 2, NULL},
    {"/list", 0, 0, NULL},
    {"/info", 0, 0, NULL},
    {NULL, 0, 0, NULL},
};

typedef struct event_type_s {
    char *code;
    void (*handler)(client_t *, char **);
} event_type_t;

// EVENTS
void handle_logged_in(UNUSED client_t *client, char **serv_resp);
void handle_logged_out(UNUSED client_t *client, char **serv_resp);
void handle_private_message(UNUSED client_t *client, char **serv_resp);
void handle_thread_reply(UNUSED client_t *client, char **serv_resp);
void handle_team_created(UNUSED client_t *client, char **serv_resp);
void handle_channel_created(UNUSED client_t *client, char **serv_resp);
void handle_thread_created(UNUSED client_t *client, char **serv_resp);
void handle_print_users(UNUSED client_t *client, char **serv_resp);
void handle_print_teams(UNUSED client_t *client, char **serv_resp);
void handle_print_channels(UNUSED client_t *client, char **serv_resp);
void handle_print_threads(UNUSED client_t *client, char **serv_resp);
void handle_thread_print_replies(UNUSED client_t *client, char **serv_resp);
void handle_pv_mess_print_mess(UNUSED client_t *client, char **serv_resp);
void handle_unknown_team(UNUSED client_t *client, char **serv_resp);
void handle_unknown_channel(UNUSED client_t *client, char **serv_resp);
void handle_unknown_thread(UNUSED client_t *client, char **serv_resp);
void handle_unknown_user(UNUSED client_t *client, char **serv_resp);
void handle_unauthorized(UNUSED client_t *client, UNUSED char **serv_resp);
void handle_already_exist(UNUSED client_t *client, UNUSED char **serv_resp);
void handle_print_user(UNUSED client_t *client, char **serv_resp);
void handle_print_team(UNUSED client_t *client, char **serv_resp);
void handle_print_channel(UNUSED client_t *client, char **serv_resp);
void handle_print_thread(UNUSED client_t *client, char **serv_resp);
void handle_print_team_created(UNUSED client_t *client, char **serv_resp);
void handle_print_channel_created(UNUSED client_t *client, char **serv_resp);
void handle_print_thread_created(UNUSED client_t *client, char **serv_resp);
void handle_print_reply_created(UNUSED client_t *client, char **serv_resp);
void handle_print_subscribed(UNUSED client_t *client, char **serv_resp);
void handle_print_unsubscribed(UNUSED client_t *client, char **serv_resp);
void handle_user_login(client_t *client, char **serv_resp);
void handle_user_logout(client_t *client, UNUSED char **serv_resp);

static event_type_t events[] __attribute__((unused)) = {
    {"49", handle_logged_in},
    {"60", handle_logged_out},
    {"70", handle_private_message},
    {"84", handle_thread_reply},
    {"100", handle_team_created},
    {"114", handle_channel_created},
    {"130", handle_thread_created},
    {"151", handle_print_users},
    {"169", handle_print_teams},
    {"186", handle_print_channels},
    {"205", handle_print_threads},
    {"225", handle_thread_print_replies},
    {"243", handle_pv_mess_print_mess},
    {"263", handle_unknown_team},
    {"276", handle_unknown_channel},
    {"288", handle_unknown_thread},
    {"300", handle_unknown_user},
    {"311", handle_unauthorized},
    {"324", handle_already_exist},
    {"337", handle_print_user},
    {"352", handle_print_team},
    {"367", handle_print_channel},
    {"384", handle_print_thread},
    {"400", handle_print_team_created},
    {"414", handle_print_channel_created},
    {"430", handle_print_thread_created},
    {"447", handle_print_reply_created},
    {"461", handle_print_subscribed},
    {"471", handle_print_unsubscribed},
    {"500", handle_user_login},
    {"501", handle_user_logout},
    {NULL, NULL},
};

// USAGE
int display_usage(void);

// ERROR HANDLING
bool handle_error(char **av);

// UTILS
char **split_string(char *str, char *token);
void destroy_array(char **array);
char **mkstw(char *str);
size_t get_array_size(char **array);
char *read_input(int fd);

// CLIENT HANDLING
client_t *init_client(char *ip, char *port);
void destroy_client(client_t *client);

// CMD HANDLING
int handle_client_command(client_t *client, fd_set *wset);
void send_serv_request(client_t *client, char **cmd, fd_set *wset);
void help(void);

// SERVER RESPONSE
int handle_server_response(client_t *client);
int recv_server(client_t *client);

#endif
