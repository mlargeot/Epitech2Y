/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** utils_str_split
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>

static bool is_string_split(size_t *i, const char *buf,
    const int split_length, const char **split)
{
    int index_split = 0;
    size_t index_buf = *i;

    for (int j = 0; j < split_length; j += 0) {
        if (split[j][index_split] == '\0') {
            *i += (index_buf - *i) - 1;
            return true;
        }
        if (buf[index_buf] == split[j][index_split]) {
            index_split++;
            index_buf++;
            continue;
        }
        j++;
        index_split = 0;
        index_buf = *i;
    }
    return false;
}

list_t *str_split_list(const char *buf, const int split_length,
    const char **split)
{
    list_t *new_list = list_new();
    size_t buf_length = strlen(buf);
    char *temp_buf = malloc(buf_length + 1);
    int temp_buf_index = 0;

    for (size_t i = 0; i <= buf_length; ++i) {
        if (is_string_split(&i, buf, split_length, split)
            || i == buf_length) {
            temp_buf[temp_buf_index] = '\0';
            list_add(new_list, temp_buf);
            temp_buf = malloc(buf_length + 1);
            temp_buf_index = 0;
            continue;
        }
        temp_buf[temp_buf_index] = buf[i];
        temp_buf_index++;
    }
    return new_list;
}
