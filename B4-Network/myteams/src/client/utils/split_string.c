/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** split_str
*/

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static size_t count_words(char *str, char *token)
{
    char *cpy = strdup(str);
    size_t words = 0;
    char *sentence = NULL;
    char *save = cpy;

    do {
        sentence = strtok_r(cpy, token, &cpy);
        words++;
    } while (sentence != NULL);
    free(save);
    return words - 1;
}

char **split_string(char *str, char *token)
{
    char *sentence = NULL;
    char *need = strdup(str);
    size_t words = count_words(str, token);
    char **arr = malloc(sizeof(char *) * (words + 1));
    size_t i = 0;
    char *save = need;

    while (i < words) {
        sentence = strtok_r(need, token, &need);
        arr[i] = strdup(sentence);
        i++;
    }
    arr[i] = NULL;
    free(save);
    return arr;
}
