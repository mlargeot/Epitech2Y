/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_file
*/

#include <xml.h>

static void init_buf(xml_file_t *new_file)
{
    new_file->buf = calloc(1, new_file->size + 1);
    if (new_file->buf == NULL)
        return;
    read(new_file->fd, new_file->buf, new_file->size);
    new_file->lignes = 1;
    for (int i = 0; new_file->buf[i] != '\0'; ++i) {
        if (new_file->buf[i] != '\n')
            new_file->lignes++;
    }
}

void xml_file_close(xml_file_t *file)
{
    if (file == NULL)
        return;
    close(file->fd);
    free(file->path);
    free(file->buf);
    free(file);
}

xml_file_t *xml_file_open(char *path, int flags, bool buff)
{
    int fd = open(path, flags);
    struct stat sb;
    xml_file_t *new_file;

    if (fd == -1)
        return NULL;
    new_file = calloc(1, sizeof(xml_file_t));
    if (new_file == NULL)
        return NULL;
    stat(path, &sb);
    new_file->size = sb.st_size;
    new_file->path = strdup(path);
    new_file->fd = fd;
    if (buff)
        init_buf(new_file);
    return new_file;
}
