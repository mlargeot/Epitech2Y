/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** parse_request
*/
#include <request.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <config.h>
#include <utils.h>

static void process_header_line(char *line, request_t *request)
{
    char *colon = strchr(line, ':');
    char *key;
    char *value;

    if (!colon)
        return;
    *colon = '\0';
    key = line;
    value = colon + 1;
    trim_whitespace(&key);
    trim_whitespace(&value);
    map_add(request->headers, strdup(key), strdup(value));
}

static void parse_headers(char *header_str, request_t *request)
{
    char *line;
    char *saveptr_header;

    line = strtok_r(header_str, "\r\n", &saveptr_header);
    while (line != NULL && request->headers->length < HEADER_ARRAY_SIZE) {
        process_header_line(line, request);
        line = strtok_r(NULL, "\r\n", &saveptr_header);
    }
}

void parse_body(request_t *request, char *saveptr)
{
    char *header_end = strstr(saveptr, "\r\n\r\n");

    request->body = xml_new(NULL);
    if (header_end) {
        *header_end = '\0';
        parse_headers(saveptr, request);
        xml_parser(request->body, header_end + 4);
    }
}

bool parse_request(int sockfd, request_t *request)
{
    char buffer[BUFFER_SIZE] = {0};
    ssize_t bytes_read = read(sockfd, buffer, sizeof(buffer) - 1);
    char *saveptr;
    char *method;
    char *path;

    if (bytes_read <= 0)
        return false;
    buffer[bytes_read] = '\0';
    method = strtok_r(buffer, " ", &saveptr);
    path = strtok_r(NULL, " ", &saveptr);
    if (!method || !path)
        return false;
    request->method = string_to_method(method);
    request->path = strdup(path);
    parse_body(request, saveptr);
    return true;
}
