/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** include
*/

#pragma once

#define _GNU_SOURCE
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <sys/select.h>
#include <stddef.h>
#include "xml.h"
#include "share/user.h"
#include "request.h"

typedef enum scope_e {
    NONE = 0,
    TEAMS,
    CHANNELS,
    THREADS
} scope_t;

typedef struct client_scope_s {
    scope_t scope;
    char teams[37];
    char channel[37];
    char thread[37];
} client_scope_t;

typedef struct client_struct {
    bool cli_logged;
    char *cli_uuid;
    char *cli_username;
    int cli_fd;
    struct sockaddr_in cli_adr;
    socklen_t adr_len;
    client_scope_t scope;
    char *cli_url;
} client_t;

typedef struct fp_s {
    char *command;
    void (*handler)(client_t *, char **);
    bool need_login;
} fp_t;

// COMMANDS
void help(__attribute__((unused)) client_t *client, char **command);
void login(client_t *client, char **command);
void logout(client_t *client, char **command);
void use(client_t *client, char **command);

void create(client_t *client, char **command);
void create_reply(client_t *client, char **command);
void create_thread(client_t *client, char **command);
void create_channel(client_t *client, char **command);
void create_team(client_t *client, char **command);
void send_message(client_t *client, char **command);
void read_message(client_t *client, char **command);
void user(client_t *client, char **command);
void users(client_t *client, char **command);

static fp_t cmds[] __attribute__((unused)) = {
    {"/help", help, false},
    {"/login", login, false},
    {"/logout", logout, true},
    {"/users", users, true},
    {"/user", user, true},
    {"/send", send_message, true},
    {"/messages", read_message, true},
    {"/subscribe", NULL, true},
    {"/subscribed", NULL, true},
    {"/unsubscribe", NULL, true},
    {"/use", use, true},
    {"/create", create, true},
    {"/list", NULL, true},
    {"/info", NULL, true},
    {NULL, NULL, false},
};

// USAGE
int display_usage(void);

// ERROR HANDLING
bool handle_error(char **av);

// CLIENT HANDLING
client_t *init_client(char *ip, char *port);
void destroy_client(client_t *client);

// READ HANDLING
int handle_client_command(client_t *client);

// SEND
void send_serv_request(client_t *client, char **cmd);

request_config_t new_config(enum method_e method, char *body,
    char *authorization);
