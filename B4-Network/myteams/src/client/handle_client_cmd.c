/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** client commads handling
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <client/cli_utils.h>

char *read_input(void)
{
    char *command = malloc(sizeof(char) * 1024);
    ssize_t len = 0;
    ssize_t readed = 0;

    if (command == NULL)
        return NULL;
    for (int i = 0; readed = read(STDIN_FILENO, command + len, 1023); i++) {
        if (readed <= 0)
            break;
        if (strstr(command, "\n") != NULL) {
            command[len + readed - 1] = '\0';
            return command;
        }
        len += readed;
        command[len] = '\0';
        command = realloc(command, (i + 1) * 1024 * sizeof(char));
    }
    free(command);
    return NULL;
}

static bool parse_cmd(char *cmd)
{
    for (size_t i = 0; cmds[i].command; i++) {
        if (!strcmp(cmd, cmds[i].command))
            return true;
    }
    return false;
}

static char **parse_input(char *cmd)
{
    char **parsed_input = mkstw(cmd);

    if (parsed_input == NULL || parsed_input[0] == NULL) {
        printf("Bad argument format\n");
        return NULL;
    }
    if (strlen(parsed_input[0]) == 0) {
        destroy_array(parsed_input);
        return NULL;
    }
    if (!parse_cmd(parsed_input[0])) {
        printf("Unknown command\n");
        destroy_array(parsed_input);
        return NULL;
    }
    return parsed_input;
}

int handle_client_command(client_t *client)
{
    char *command = read_input();
    char **parsed_input = NULL;

    if (command == NULL)
        return 84;
    parsed_input = parse_input(command);
    if (parsed_input != NULL)
        send_serv_request(client, parsed_input);
    free(command);
    return 0;
}
