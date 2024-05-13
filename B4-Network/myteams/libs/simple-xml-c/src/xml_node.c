/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_node
*/

#include <xml.h>

xml_node_t *xml_new_node(xml_node_t *parent, char *tag, char *inner_text)
{
    xml_node_t *node = calloc(1, sizeof(xml_node_t));

    node->parent = parent;
    node->tag = tag ? strdup(tag) : NULL;
    node->inner_text = inner_text ? strdup(inner_text) : NULL;
    node->list_attributes = list_new();
    node->list_children = list_new();
    if (parent)
        list_add(parent->list_children, node);
    return node;
}

void xml_node_free(xml_node_t *xml_node)
{
    for (list_node_t *node = xml_node->list_attributes->head;
        node; node = node->next) {
        free(((xml_attribute_t *)node->value)->value);
        free(((xml_attribute_t *)node->value)->key);
        free(node->value);
    }
    list_clear(xml_node->list_attributes);
    free(xml_node->list_attributes);
    for (list_node_t *node = xml_node->list_children->head;
        node; node = node->next)
        xml_node_free(node->value);
    list_clear(xml_node->list_children);
    free(xml_node->list_children);
    free(xml_node);
}
