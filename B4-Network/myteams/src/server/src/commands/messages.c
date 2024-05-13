/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** messages
*/

#include <myteams_server.h>

int send_messages_list(server_t *server, client_t *client,
    message_t **messages)
{
    char *response = NULL;
    char *tmp = NULL;
    char *timestamp = NULL;

    asprintf(&response, "243;");
    for (int i = 0; messages[i]; i++) {
        timestamp = get_time_str(messages[i]->timestamp);
        asprintf(&tmp, "%s\"%s\" \"%s\" \"%s\";", response,
            messages[i]->sender->uuid, timestamp,
            messages[i]->message);
        free(response);
        response = tmp;
        tmp = NULL;
    }
    send(client->sock, response, strlen(response), 0);
    free(response);
}

int messages(server_t *server, client_t *client,
    char **cmds, char *token)
{
    user_t *user = db_get_user(token);
    user_t *user2 = db_get_user(cmds[1]);
    message_t **messages = NULL;

    if (user2 == NULL)
        return send_user_not_found(server, client, cmds[1]);
    messages = db_get_messages_between(user->uuid, user2->uuid);
    send_messages_list(server, client, messages);
    return 0;
}
