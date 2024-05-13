/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** help command client side
*/

#include <stdio.h>
#include <client/cli_utils.h>

static void display_help_end(void)
{
    printf("When team_uuid, channel_uuid and thread_uuid are defined "
    "(/use “team_uuid” “channel_uuid” “thread_uuid”):\n\t"
    "/create [comment_body]: create a new reply\n\t"
    "/list: list all existing replies\n\t"
    "/info: display currently selected thread details\n");
}

static void display_help_next(void)
{
    printf("\t/list: based on the context, list all the sub resources "
    "(see below)\n\t/info: based on the context, display details of the "
    "current resource (see below)\n\n");
    printf("CREATE / LIST / INFO:\n\n"
    "When the context is not defined (/use):\n\t"
    "/create [team_name] [team_description]: create a new team\n\t"
    "/list: list all existing teams\n\t"
    "/info: display currently logged-in user details\n"
    "When team_uuid is defined (/use “team_uuid”):\n\t"
    "/create [channel_name] [channel_description]: create a new channel"
    "\n\t/list: list all existing channels\n\t"
    "/info : display currently selected team details\n"
    "When team_uuid and channel_uuid are defined (/use “team_uuid” "
    "“channel_uuid”):\n\t/create [thread_title] [thread_message]: create "
    "a new thread\n\t/list: list all existing threads\n\t/info: display "
    "currently selected channel details\n");
    return display_help_end();
}

void help(__attribute__((unused)) client_t *client, char **command)
{
    if (get_array_size(command) > 1) {
        printf("Invalid command format\n");
        return;
    }
    printf("Here is the following commands for the client:\n"
    "\t/help: show help\n\t/login [user_name]: set the user_name used by"
    " client\n\t/logout: disconnect the client from the server\n\t"
    "/users: get the list of all users that exist on the domain\n\t"
    "/user [user_uuid]: get details about the requested user\n\t"
    "/send [user_uuid] [message_body]: send a message to specific user\n\t"
    "/messages [user_uuid]: list all messages exchanged with the specified "
    "user\n\t/subscribe [team_uuid]: subscribe to the events of a team and "
    "its sub directories (enable reception of all events from a team)\n\t"
    "/subscribed ?[team_uuid]: list all subscribed teams or list all "
    "users subscribed to a team\n\t/unsubscribe [team_uuid]: unsubscribe "
    "from a team\n\t/use ?[team_uuid] ?[channel_uuid] ?[thread_uuid]: "
    "Sets the command context to a team/channel/thread\n\t/create: based "
    "on the context, create the sub resource (see below)\n");
    return display_help_next();
}
