/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_get_inner_text
*/

#include <xml.h>

size_t xml_get_node_inner_text(xml_node_t *node, char *buf)
{
    size_t index = 0;

    for (; buf[index] != '\0'; ++index) {
        if (buf[index] == '<')
            break;
    }
    if (index > 0) {
        node->inner_text = calloc(1, sizeof(char) * (index) + 1);
        strncpy(node->inner_text, buf, index);
    }
    return index;
}
