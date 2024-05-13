/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** send_response
*/

#include <response.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

static size_t get_response_length(response_t *response, size_t body_length)
{
    size_t length = 0;

    length += snprintf(NULL, 0, "HTTP/1.1 %d %s\r\n",
        response->status_code,
        get_status_message(response->status_code));
    for (map_node_t *node = response->headers->head; node; node = node->next)
        length += strlen(node->key) + strlen(node->value) + 4;
    length += 2;
    if (response->body)
        length += body_length;
    return length + 2;
}

static void add_content_length_header(response_t *response, size_t body_length)
{
    char *str = malloc(20);

    if (!str) {
        fprintf(stderr, "Failed to allocate "
            "memory for Content-Length header\n");
        return;
    }
    sprintf(str, "%zu", body_length);
    map_add(response->headers, "Content-Length", str);
}

static char *format_http_response(response_t *response, char *str_body)
{
    size_t estimated_length = get_response_length(response, strlen(str_body));
    char *http_response = malloc(estimated_length + 1);
    size_t offset;

    if (!http_response) {
        fprintf(stderr, "Failed to allocate memory for HTTP response\n");
        return NULL;
    }
    offset = snprintf(http_response, estimated_length,
        "HTTP/1.1 %d %s\r\n",
        response->status_code, get_status_message(response->status_code));
    for (map_node_t *node = response->headers->head; node; node = node->next)
        offset += sprintf(http_response + offset,
            "%s: %s\r\n", node->key, (char *)node->value);
    strcat(http_response + offset, "\r\n");
    if (str_body)
        strcat(http_response + offset, str_body);
    return http_response;
}

void send_response(int client_fd, response_t *response)
{
    char *http_response;
    char *str_body = response->body ? xml_str(response->body) : "";

    add_content_length_header(response, strlen(str_body));
    http_response = format_http_response(response, str_body);
    if (!http_response) {
        if (response->status_code != INTERNAL_SERVER_ERROR) {
            new_internal_server_error(response,
                "Failed to format HTTP response");
            send_response(client_fd, response);
        }
        return;
    }
    dprintf(client_fd, "%s", http_response);
    free(http_response);
}
