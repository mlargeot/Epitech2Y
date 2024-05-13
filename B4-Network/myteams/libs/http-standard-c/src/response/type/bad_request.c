/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** bad_request
*/

#include <response.h>
#include <string.h>

response_t *new_bad_request(response_t *response, char *message)
{
    response->status_code = 400;
    response->body = xml_error(400, message);
    map_add(response->headers, "Content-Type", "application/xml");
    return response;
}
