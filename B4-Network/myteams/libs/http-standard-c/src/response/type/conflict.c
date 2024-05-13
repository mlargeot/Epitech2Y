/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** conflict
*/

#include <response.h>
#include <string.h>

response_t *new_conflict(response_t *response, char *message)
{
    response->status_code = 409;
    response->body = xml_error(409, message);
    map_add(response->headers, "Content-Type", "application/xml");
    return response;
}
