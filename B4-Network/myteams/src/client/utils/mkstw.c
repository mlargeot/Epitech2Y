/*
** EPITECH PROJECT, 2023
** stw
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void get_arg(char *str, int *i, char ***stw)
{
    int j = 0;
    char *arg = NULL;
    int len = 0;

    for (; (*stw)[len]; len++);
    if (str[0] == '"') {
        for (j = 1; str[j] && str[j] != '"'; j++);
        arg = strndup(str + 1, j - 1);
        *i += j + 1;
    }
    if (str[0] && str[0] != '"') {
        for (j = 0; str[j] && !(str[j] == ' ' || str[j] == '\t'); j++);
        arg = strndup(str, j);
        *i += j;
    }
    *stw = realloc(*stw, sizeof(char *) * (len + 2));
    (*stw)[len] = arg;
    (*stw)[len + 1] = NULL;
}

char **mkstw(char *str)
{
    int i = 0;
    int nb_quote = 0;
    char **stw = malloc(sizeof(char *) * 1);

    stw[0] = NULL;
    for (int i = 0; str[i]; i++)
        if (str[i] == '"')
            nb_quote++;
    if (nb_quote % 2 != 0)
        return NULL;
    while (str[i]) {
        for (; str[i] == ' ' || str[i] == '\t'; i++);
        get_arg(str + i, &i, &stw);
    }
    return stw;
}
