/*
** EPITECH PROJECT, 2023
** xml_free.c
** File description:
** desc
*/

#include <xml.h>
#include <stdlib.h>

void xml_free(xml_t *doc)
{
    xml_node_free(doc->root);
    free(doc);
}
