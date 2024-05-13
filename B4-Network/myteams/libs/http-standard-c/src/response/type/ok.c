/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** ok
*/

#include <response.h>
#include <string.h>

response_t *new_ok(response_t *response, xml_t *body)
{
    response->status_code = 200;
    response->body = body;
    map_add(response->headers, "Content-Type", "application/xml");
    return response;
}
