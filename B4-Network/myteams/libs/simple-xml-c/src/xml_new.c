/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_new
*/

#include <xml.h>

xml_t *xml_new(char *tag)
{
    xml_t *doc = calloc(1, sizeof(xml_t));

    if (doc == NULL)
        return NULL;
    doc->root = xml_new_node(NULL, tag ? tag : NULL, NULL);
    return doc;
}
