# Teams Protocol

version: 1.0
april 20, 2024

## 1. Introduction

This document describes the Teams Protocol, a text-based protocol for communication between a client and a server.

## 2. Server Requests

### Convention

Commands are sent from the client to the server in the following format:

`/command ["argument1"] ["argument2"] ...;["*token*"]`

> Quoting of arguments is optional, it's only if you want space or tabs in it.
Its also important to dont put space beside **;** to falicitate the parssing.


### Possible requests

The client can send the following requests to the server:

- **/login**
*token*: not_required
argument: user_name
*usage*: `/login ["user_name"]`
*details*: Set the user_name used by client.

- **/logout**
  *token*: required
  *usage*: `/logout`
  *details*: Disconnect the client from the server.

- **/users**
  *token*: required
  *usage*: `/users`
  *details*: Get the list of all users that exist on the domain.

- **/user**
  *token*: required
  argument: user_uuid
  *usage*: `/user ["user_uuid"]`
  *details*: Get *details* about the requested user.

- **/send**
  *token*: required
  arguments: user_uuid, message_body
  *usage*: `/send ["user_uuid"] ["message_body"]`
  *details*: Send a message to a specific user.

- **/messages**
  *token*: required
  argument: user_uuid
  *usage*: `/messages ["user_uuid"]`
  *details*: List all messages exchanged with the specified user.

- **/subscribe**
  *token*: required
  argument: team_uuid
  *usage*: `/subscribe ["team_uuid"]`
  *details*: Subscribe to the events of a team and its subdirectories.

- **/subscribed**
  *token*: required
  argument: team_uuid (optional)
  *usage*: `/subscribed ?["team_uuid"]`
  *details*: List all subscribed teams or list all users subscribed to a team.

- **/unsubscribe**
  *token*: required
  argument: team_uuid
  *usage*: `/unsubscribe ["team_uuid"]`
  *details*: Unsubscribe from a team.

- **/use**
  *token*: required
  arguments: team_uuid, channel_uuid, thread_uuid (optional)
  *usage*: `/use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"]`
  *details*: Sets the command context to a team/channel/thread.

- **/create**
  *token*: required
  arguments: resource_name, resource_description (optional)
  - *usage*: `/create ["team_name"] ["team_description"]`
    *details*: create a team when the context is undefined (/use)
  - *usage*: `/create ["channel_name"] ["channel_description"]`
    *details*: create a channel when the context is a team (/use ["team_uuid"])
  - *usage*: `/create ["thread_name"] ["thread_description"]`
    *details*: create a thread when the context is a channel (/use ["team_uuid"] ["channel_uuid"])
  - *usage*: `/create ["reply_body"]`
    *details*: create a reply when the context is a thread (/use ["team_uuid"] ["channel_uuid"] ["thread_uuid"])

- **/list**
  *token*: required
  *usage*: `/list`
  *details*: List all existing resources based on the context (teams/channels/threads/replies).

- **/info**
  *token*: required
  *usage*: `/info`
  *details*: Display *details* of the current resource based on the context (user/team/channel/thread).

## 4. Server Responses && ping

### Asynchronous Server-Client Communication

In this protocol, the communication between the server and client is designed to be asynchronous. This means that the client does not necessarily need to wait for a response from the server after sending a request. Instead, the server sends periodic "pings" or notifications to the client, which serve as updates or responses to the client's previous requests.

#### Server Response Format

The server response follows a specific format to ensure clarity and consistency:

`[code];["argument_1"] ["argument_2"] ...;...;`

The code is separated from the rest of the response, after you use commat to separate object. Most of the requests contain one object (logged user information for exemple), so it look like this: `[code];["argument_1"] ["argument_2"];`
But in some case a response contain a list of object (list of teams), so a response could look like this: `[code];["argument_1"] ["argument_2"];["argument_1"] ["argument_2"];["argument_1"] ["argument_2"];["argument_1"] ["argument_2"];`

> All the parameter contained in the response is defined by the code, and in the next section.
Its also important to dont put space beside **;** to falicitate the parssing.

### Responses

- **49**: `handle_logged_in`
  - *Details*: Triggered when a user logs in.
  - *Response Format*: `49;["user_uuid"] ["user_name"];`

- **60**: `handle_logged_out`
  - *Details*: Triggered when a user logs out.
  - *Response Format*: `60;["user_uuid"] ["user_name"];`

- **70**: `handle_private_message`
  - *Details*: Triggered when a private message is received.
  - *Response Format*: `70;["sender_uuid"] ["message_body"];`

- **84**: `handle_thread_reply`
  - *Details*: Triggered when a reply is added to a thread.
  - *Response Format*: `84;["thread_uuid"] ["reply_body"];`

- **100**: `handle_team_created`
  - *Details*: Triggered when a team is created.
  - *Response Format*: `100;["team_uuid"] ["team_name"];`

- **114**: `handle_channel_created`
  - *Details*: Triggered when a channel is created.
  - *Response Format*: `114;["channel_uuid"] ["channel_name"];`

- **130**: `handle_thread_created`
  - *Details*: Triggered when a thread is created.
  - *Response Format*: `130;["thread_uuid"] ["thread_title"];`

- **151**: `handle_print_users`
  - *Details*: Triggered when a list of users is requested.
  - *Response Format*: `151;["user_uuid1"] ["user_name1"];["user_uuid2"] ["user_name2"];...`

- **169**: `handle_print_teams`
  - *Details*: Triggered when a list of teams is requested.
  - *Response Format*: `169;["team_uuid1"] ["team_name1"];["team_uuid2"] ["team_name2"];...`

- **186**: `handle_print_channels`
  - *Details*: Triggered when a list of channels is requested.
  - *Response Format*: `186;["channel_uuid1"] ["channel_name1"];["channel_uuid2"] ["channel_name2"];...`

- **205**: `handle_print_threads`
  - *Details*: Triggered when a list of threads is requested.
  - *Response Format*: `205;["thread_uuid1"] ["thread_title1"];["thread_uuid2"] ["thread_title2"];...`

- **225**: `handle_thread_print_replies`
  - *Details*: Triggered when a list of replies in a thread is requested.
  - *Response Format*: `225;["reply_uuid1"] ["reply_body1"];["reply_uuid2"] ["reply_body2"];...`

- **243**: `handle_pv_mess_print_mess`
  - *Details*: Triggered when a list of private messages is requested.
  - *Response Format*: `243;["message_uuid1"] ["message_body1"];["message_uuid2"] ["message_body2"];...`

- **263**: `handle_unknown_team`
  - *Details*: Triggered when an unknown team is accessed.
  - *Response Format*: `263;["team_uuid"];`

- **276**: `handle_unknown_channel`
  - *Details*: Triggered when an unknown channel is accessed.
  - *Response Format*: `276;["channel_uuid"];`

- **288**: `handle_unknown_thread`
  - *Details*: Triggered when an unknown thread is accessed.
  - *Response Format*: `288;["thread_uuid"];`

- **300**: `handle_unknown_user`
  - *Details*: Triggered when an unknown user is accessed.
  - *Response Format*: `300;["user_uuid"];`

- **311**: `handle_unauthorized`
  - *Details*: Triggered when the client is unauthorized to perform an action.
  - *Response Format*: `311;["error_message"];`

- **324**: `handle_already_exist`
  - *Details*: Triggered when an entity already exists.
  - *Response Format*: `324;["error_message"];`

- **337**: `handle_print_user`
  - *Details*: Triggered when user details are requested.
  - *Response Format*: `337;["user_uuid"] ["user_name"];`

- **352**: `handle_print_team`
  - *Details*: Triggered when team details are requested.
  - *Response Format*: `352;["team_uuid"] ["team_name"];`

- **367**: `handle_print_channel`
  - *Details*: Triggered when channel details are requested.
  - *Response Format*: `367;["channel_uuid"] ["channel_name"];`

- **384**: `handle_print_thread`
  - *Details*: Triggered when thread details are requested.
  - *Response Format*: `384;["thread_uuid"] ["thread_title"];`

- **400**: `handle_print_team_created`
  - *Details*: Triggered when a team creation is successful.
  - *Response Format*: `400;["team_uuid"] ["team_name"];`

- **414**: `handle_print_channel_created`
  - *Details*: Triggered when a channel creation is successful.
  - *Response Format*: `414;["channel_uuid"] ["channel_name"];`

- **430**: `handle_print_thread_created`
  - *Details*: Triggered when a thread creation is successful.
  - *Response Format*: `430;["thread_uuid"] ["thread_title"];`

- **447**: `handle_print_reply_created`
  - *Details*: Triggered when a reply creation is successful.
  - *Response Format*: `447;["reply_uuid"] ["reply_body"];`

- **461**: `handle_print_subscribed`
  - *Details*: Triggered when subscription to a team is successful.
  - *Response Format*: `461;["team_uuid"] ["team_name"];`

- **471**: `handle_print_unsubscribed`
  - *Details*: Triggered when unsubscription from a team is successful.
  - *Response Format*: `471;["team_uuid"] ["team_name"];`

- **500**: `handle_user_login`
  - *Details*: Triggered when a user logs in.
  - *Response Format*: `500;["user_uuid"] ["user_name"];`

- **501**: `handle_user_logout`
  - *Details*: Triggered when a user logs out.
  - *Response Format*: `501;["user_uuid"] ["user_name"];`

## 8. Author's Address

*alexis.boitel@epitech.eu*
