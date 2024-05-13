/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** send_server
*/

#include <myteams_server.h>

int send_message_to_user(server_t *server, user_t *user, user_t *user_to_send,
    char *message)
{
    char *response = NULL;
    char *time_str = get_time_str(time(NULL));

    for (size_t i = 0; server->clients[i] != NULL; i++) {
        if (strcmp(server->clients[i]->uuid, user_to_send->uuid) == 0) {
            asprintf(&response, "243;\"%s\" \"%s\" \"%s\";\n",
                user->uuid, time_str, message);
            send(server->clients[i]->sock, response, strlen(response), 0);
            free(response);
        }
    }
    return 0;
}

int server_send(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(token);
    user_t *user_to_send = db_get_user(cmds[1]);
    char *response = NULL;

    if (user == NULL)
        return send_user_not_found(server, client, token);
    if (user_to_send == NULL)
        return send_user_not_found(server, client, cmds[1]);
    server_event_private_message_sended(user->uuid,
        user_to_send->uuid, cmds[2]);
    send_message_to_user(server, user, user_to_send, cmds[2]);
    return 0;
}
