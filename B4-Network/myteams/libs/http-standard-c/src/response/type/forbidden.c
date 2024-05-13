/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** forbidden
*/

#include <response.h>
#include <string.h>

response_t *new_forbidden(response_t *response, char *message)
{
    response->status_code = 403;
    response->body = xml_error(403, message);
    map_add(response->headers, "Content-Type", "application/xml");
    return response;
}
