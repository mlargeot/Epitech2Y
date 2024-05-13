/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** handle_client
*/

#include <stdio.h>
#include <router.h>
#include <string.h>
#include <regex.h>
#include <config.h>

void convert_path_to_regex(const char *template_path, char *regex_buffer)
{
    const char *cursor = template_path;

    *regex_buffer = '^';
    regex_buffer++;
    while (*cursor) {
        if (*cursor != ':') {
            *regex_buffer = *cursor;
            regex_buffer++;
            cursor++;
            continue;
        }
        strcat(regex_buffer, "([^/]+)");
        regex_buffer += strlen("([^/]+)");
        cursor++;
        while (*cursor && *cursor != '/')
            cursor++;
    }
    regex_buffer++;
    *regex_buffer = '$';
    *regex_buffer = '\0';
}

bool check_regex(request_t *request, regex_t *regex)
{
    char regex_pattern[1024] = {0};

    convert_path_to_regex(request->route->template_path, regex_pattern);
    if (regcomp(regex, regex_pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Failed to compile regex\n");
        return false;
    }
    return true;
}

void extract_params(request_t *request)
{
    regmatch_t matches[PARAM_ARRAY_SIZE];
    regex_t regex;
    char found_param[PARAM_SIZE];

    if (!check_regex(request, &regex))
        return;
    if (regexec(&regex, request->path, PARAM_ARRAY_SIZE, matches, 0) == 0) {
        for (int i = 1; i < PARAM_ARRAY_SIZE && matches[i].rm_so != -1; i++) {
            found_param[0] = '\0';
            strncpy(found_param, request->path + matches[i].rm_so,
                    matches[i].rm_eo - matches[i].rm_so);
            found_param[matches[i].rm_eo - matches[i].rm_so] = '\0';
            map_add(request->params, strdup(
                request->route->param_names[i - 1]), strdup(found_param));
        }
    }
    regfree(&regex);
}
