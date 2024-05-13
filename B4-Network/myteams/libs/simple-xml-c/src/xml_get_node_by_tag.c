/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_get_node_by_tag
*/

#include <xml.h>

xml_node_t *xml_get_node_by_tag(xml_node_t *data, char *tag)
{
    xml_node_t *res;

    if (data == NULL || tag == NULL || data->tag == NULL)
        return NULL;
    if (strcmp(data->tag, tag) == 0)
        return data;
    for (list_node_t *node = data->list_children->head;
        node; node = node->next) {
        res = xml_get_node_by_tag(node->value, tag);
        if (res != NULL)
            return res;
    }
    return NULL;
}
