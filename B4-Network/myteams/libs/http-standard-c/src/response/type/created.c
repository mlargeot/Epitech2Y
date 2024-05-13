/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** create
*/

#include <response.h>
#include <string.h>

response_t *new_created(response_t *response, xml_t *body)
{
    response->status_code = 201;
    response->body = body;
    map_add(response->headers, "Content-Type", "application/xml");
    return response;
}
