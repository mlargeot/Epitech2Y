/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_add_data
*/

#include <xml.h>

void xml_add_data(xml_t *doc, xml_node_t **current,
    size_t *index, char *buf)
{
    if (*current == NULL)
        *current = doc->root;
    else
        *current = xml_new_node(*current, NULL, NULL);
    *index += xml_get_node_tag(*current, buf + *index);
    *index += xml_get_node_inner_text(*current, buf + *index);
}
