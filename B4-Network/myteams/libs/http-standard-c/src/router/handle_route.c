/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** handle_route
*/

#include <router.h>
#include <unistd.h>
#include <stdlib.h>

static bool execute_route_logic(route_t *route, request_t *request,
    response_t *response)
{
    if (route->middleware) {
        if (!route->middleware(request, response))
            return false;
    }
    if (route->handler) {
        route->handler(request, response);
        return true;
    }
    new_not_implemented(response, "Route not implemented");
    return false;
}

response_t *handle_route(list_t *router, request_t *request)
{
    route_t *route = find_route(router, request->path, request->method);
    response_t *response = calloc(1, sizeof(response_t));

    if (response == NULL)
        return NULL;
    response->headers = map_new();
    response->body = NULL;
    if (route == NULL)
        return new_not_found(response, "Route not found");
    request->route = route;
    extract_params(request);
    execute_route_logic(route, request, response);
    return response;
}
