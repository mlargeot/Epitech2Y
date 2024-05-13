/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml_parsser
*/

#include "xml.h"
#include "utils.h"
#include <stdio.h>

static int xml_is_valid_end_tag(char *buf, xml_node_t *current, size_t *index)
{
    unsigned long temp_len;

    if (buf[*index + 1] == '/') {
        temp_len = strlen(current->tag);
        if (strncmp(current->tag, buf + (*index + 2), temp_len - 1) != 0 ||
            *(buf + (*index + 2 + temp_len)) != '>')
            return 0;
        *index += temp_len;
        return 1;
    }
    return 2;
}

static int handle_tag(char *buf, xml_node_t **current, size_t *index)
{
    int valid_end = xml_is_valid_end_tag(buf, *current, index);

    if (valid_end == 1) {
        *current = (*current)->parent;
        return 1;
    } else if (valid_end == 0) {
        return 0;
    }
    return 2;
}

static bool parse_loop(xml_t *doc, char *buf, xml_node_t **current)
{
    size_t index = 0;
    int result;

    while (buf[index] != '\0') {
        if (buf[index] != '<') {
            index++;
            continue;
        }
        result = handle_tag(buf, current, &index);
        if (result == 0)
            return false;
        if (result == 2)
            xml_add_data(doc, current, &index, buf);
    }
    return true;
}

bool xml_parser(xml_t *doc, char *content)
{
    char *buf = str_match(content, "<.*>");
    xml_node_t *current = NULL;

    if (buf == NULL) {
        fprintf(stderr, "No tags found in content.\n");
        return false;
    }
    return parse_loop(doc, buf, &current);
}

//bool xml_parser(xml_t *doc, char *content)
//{
//    size_t index = 0;
//    char *buf = str_match(content, "<.*>");
//    xml_node_t *current = NULL;
//    int valid_end;
//
//    if (buf == NULL)
//        return false;
//    while (buf[index] != '\0') {
//        if (buf[index] != '<') {
//            index++;
//            continue;
//        }
//        valid_end = xml_is_valid_end_tag(buf, current, &index);
//        if (valid_end == 1) {
//            current = current->parent;
//            continue;
//        }
//        if (valid_end == 0)
//            return false;
//        xml_add_data(doc, &current, &index, buf);
//    }
//    return true;
//}
