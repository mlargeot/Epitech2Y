/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** not_found
*/

#include <response.h>
#include <string.h>

response_t *new_not_found(response_t *response, char *message)
{
    response->status_code = 404;
    response->body = xml_error(404, message);
    map_add(response->headers, "Content-Type", "application/xml");
    return response;
}
