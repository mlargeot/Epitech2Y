/*
** EPITECH PROJECT, 2024
** my_ftp
** File description:
** server header file
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #define UNUSED __attribute__((unused))
    #define _GNU_SOURCE

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/select.h>
    #include <stdbool.h>
    #include <stdio.h>

typedef struct command_s {
    char *cmd;
    int (*command)();
} cmd_t;

enum client_state {
    NEUTRAL,
    PASSIVE,
    ACTIVE,
};

typedef struct server_s {
    int serv_fd;
    struct sockaddr_in serv_addr;
    socklen_t serv_len;
    fd_set rset;
    fd_set wset;
    char *default_dir;
    int max_fd;
    int port;
} server_t;

typedef struct data_transfer_s {
    int transfer_fd;
    struct sockaddr_in transfer_socket;
    socklen_t serv_len;
    char *ip_adress;
    int port;
} data_t;

typedef struct clients_s {
    int cli_fd;
    char *working_dir;
    bool is_connected;
    char *username;
    bool valid_user;
    char **command;
    int status;
    int data_fd;
    data_t *client_data_t;
} clients_t;

//INIT SERVER
server_t *init_serv(int port);
server_t *destroy_serv(server_t *serv);

//SERVER HANDLING
void reset_socket(server_t *server, clients_t *clients);
int handle_connection(server_t *serv, clients_t *clients);
int handle_command(server_t *serv, clients_t *clients);
int connect_data_transfer(clients_t *client);

//CLIENTS HANDLING
void destroy_clicmd(clients_t *client);
void reset_clients_fd(clients_t *cli);
bool is_full(clients_t *clients);
void reply_clients(server_t *serv, clients_t *clients);
int reset_user(clients_t *client);

//COMMANDS
int exec_cdup(server_t *serv, clients_t *client);
int exec_cwd(server_t *serv, clients_t *client);
int exec_dele(server_t *serv, clients_t *client);
int exec_help(UNUSED server_t *serv, clients_t *client);
int exec_list(server_t *serv, clients_t *client);
int exec_noop(UNUSED server_t *serv, clients_t *client);
int exec_pasv(server_t *serv, clients_t *client);
int exec_port(server_t *serv, clients_t *client);
int exec_pwd(server_t *serv, clients_t *client);
int exec_quit(UNUSED server_t *serv, clients_t *client);
int exec_retr(server_t *serv, clients_t *client);
int exec_stor(server_t *serv, clients_t *client);
int exec_user(UNUSED server_t *serv, clients_t *client);
int exec_pass(UNUSED server_t *serv, clients_t *client);

//UTILS
char **split_str(char *str, char *token);
int handle_path(char *n_path, char *def_path);
int close_cli_datasoc(clients_t *client);

#endif /* !SERVER_H_ */
