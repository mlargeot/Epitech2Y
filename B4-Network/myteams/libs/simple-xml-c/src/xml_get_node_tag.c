/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_get_node_tag
*/

#include <xml.h>
#include <utils.h>

static xml_attribute_t *parse_attribute(char *match, size_t *end_pos)
{
    xml_attribute_t *attr = calloc(1, sizeof(xml_attribute_t));
    size_t key_end = str_index_of(match, "=\"");
    size_t value_start;
    size_t value_end;

    if (!attr)
        return NULL;
    attr->key = strndup(match, key_end);
    value_start = key_end + 2;
    value_end = str_index_of(match + value_start, "\"");
    attr->value = strndup(match + value_start, value_end);
    *end_pos = value_start + value_end + 1;
    return attr;
}

static char *find_next_attribute(char *current)
{
    if (*current == '>')
        return NULL;
    return str_match(current, " .*=\".*\"");
}

static void get_node_tag_attribute(xml_node_t *node, char *buf)
{
    char *match = str_match(buf, " .*=\".*\"");
    size_t end_pos;
    xml_attribute_t *attr;

    if (!match)
        return;
    while (match) {
        end_pos = 0;
        attr = parse_attribute(match, &end_pos);
        if (!attr)
            break;
        list_add(node->list_attributes, attr);
        match = find_next_attribute(match + end_pos);
    }
}

size_t xml_get_node_tag(xml_node_t *node, char *buf)
{
    char *match = str_match(buf, "<.*>");
    size_t i = 0;
    size_t tag_end;

    if (match == NULL)
        return 0;
    get_node_tag_attribute(node, match);
    tag_end = str_index_of(match, " ");
    for (; match[i] != '>'; ++i);
    if (tag_end < i && tag_end > 0) {
        node->tag = calloc(1, tag_end);
        strncpy(node->tag, match + 1, tag_end - 1);
    } else {
        node->tag = calloc(1, i);
        strncpy(node->tag, match + 1, i - 1);
    }
    return i + 1;
}
