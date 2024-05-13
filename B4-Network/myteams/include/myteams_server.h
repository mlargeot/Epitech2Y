/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** include
*/

#ifndef _MYTEAMS_SERVER_H__
    #define _MYTEAMS_SERVER_H__

    #define _GNU_SOURCE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <unistd.h>
    #include <stdbool.h>

    #include <netdb.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/select.h>
    #include <poll.h>

    #include <db/db.h>
    #include <logging_server.h>

    #include <my_time.h>

    #define SA struct sockaddr

    #define BUFFER_SIZE 1024
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

typedef struct client_s {
    int sock;
    struct sockaddr_in adr;
    socklen_t adr_len;
    char *uuid;
} client_t;

typedef struct server_s {
    int controlSock;
    struct sockaddr_in controlAddr;
    int port;

    fd_set readFds;
    fd_set writeFds;

    client_t **clients;
} server_t;


server_t *init_server(int port);
int loop(server_t *server);
void set_fd(server_t *server);
void new_client(server_t *server);
int tab_len(void **tab);
char *uuid_gen(char *dest);
int handle_command(server_t *server);

typedef struct route_s {
    char *command;
    int (*handler)(server_t *, client_t *, char **, char *);
} route_t;

int login(server_t *server, client_t *client,
    char **cmds, char *token);
int logout(server_t *server, client_t *client,
    char **cmds, char *token);
int users(server_t *server, client_t *client,
    char **cmds, char *token);
int user(server_t *server, client_t *client,
    char **cmds, char *token);
int server_send(server_t *server, client_t *client,
    char **cmds, char *token);
int messages(server_t *server, client_t *client,
    char **cmds, char *token);
int subscribe(server_t *server, client_t *client,
    char **cmds, char *token);
int subscribed(server_t *server, client_t *client,
    char **cmds, char *token);
int unsubscribe(server_t *server, client_t *client,
    char **cmds, char *token);
int use(server_t *server, client_t *client,
    char **cmds, char *token);
int create(server_t *server, client_t *client,
    char **cmds, char *token);
int list(server_t *server, client_t *client,
    char **cmds, char *token);
int info(server_t *server, client_t *client,
    char **cmds, char *token);
int unauthorized(server_t *server, client_t *client,
    char **cmds, char *token);
int not_found(server_t *server, client_t *client,
    char **cmds, char *token);

static route_t routes[] __attribute__((unused)) = {
    {"/login", login},
    {"/logout", logout},
    {"/users", users},
    {"/user", user},
    {"/send", server_send},
    {"/messages", messages},
    {"/subscribe", subscribe},
    {"/subscribed", subscribed},
    {"/unsubscribe", unsubscribe},
    {"/use", use},
    {"/create", create},
    {"/list", list},
    {"/info", info},
    {NULL, NULL},
};

char **mkstw(char *str);
char **my_stw(char *str, char *sep);
int lenstw(char **stw);
void remove_first_elem(void **tab);
int send_user_not_found(server_t *server, client_t *client, char *uuid);
int send_team_not_found(server_t *server, client_t *client, char *uuid);
int send_thread_not_found(server_t *server, client_t *client, char *uuid);
int send_channel_not_found(server_t *server, client_t *client, char *uuid);
int send_already_exist(server_t *server, client_t *client, char *uuid);
int send_logout_to_all(server_t *server, user_t *user);
int ping_new_team(server_t *server, team_t *team);

#endif
