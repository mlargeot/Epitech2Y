/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** fetch_request
*/

#include <request.h>
#include <response.h>
#include <client/myteams_cli.h>

static void init_config(request_config_t *config, method_t method, char *body)
{
    config->method = method;
    config->headers[0] = (request_header_t){"Content-Type", "application/xml"};
    config->headers[1] = (request_header_t){NULL, NULL};
    config->body = body;
}

response_t *fetch_url(client_t *client, const char *url,
    method_t method, char *body)
{
    response_t *response;
    char *route = NULL;
    char *authorization = NULL;
    request_config_t config;

    init_config(&config, method, body);
    if (client->cli_logged) {
        asprintf(&authorization, "Bearer %s", client->cli_uuid);
        config.headers[1] = (request_header_t){"Authorization", authorization};
        config.headers[2] = (request_header_t){NULL, NULL};
    } else {
        config.headers[1] = (request_header_t){NULL, NULL};
    }
    asprintf(&route, "%s%s", client->cli_url, url);
    response = fetch(route, &config);
    free(route);
    if (authorization != NULL)
        free(authorization);
    return response;
}
