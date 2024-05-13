/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** internal_server_error
*/

#include <response.h>
#include <string.h>

response_t *new_internal_server_error(response_t *response, char *message)
{
    response->status_code = 500;
    response->body = xml_error(500, message);
    map_add(response->headers, "Content-Type", "application/xml");
    return response;
}
