/*
** EPITECH PROJECT, 2024
** simple-xml-c
** File description:
** xml
*/

#pragma once

#include <list.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

typedef struct xml_file {
    int fd;
    char *path;
    size_t size;
    char *buf;
    size_t lignes;
} xml_file_t;

typedef struct xml_attribute {
    char *key;
    char *value;
} xml_attribute_t;

typedef struct xml_node {
    char *tag;
    list_t *list_attributes;
    char *inner_text;
    struct xml_node *parent;
    list_t *list_children;
} xml_node_t;

typedef struct xml {
    char *path;
    xml_node_t *root;
} xml_t;

xml_t *xml_load(const char *path);
void xml_free(xml_t *doc);
xml_node_t *xml_new_node(xml_node_t *parent, char *tag, char *inner_text);
void xml_node_free(xml_node_t *node);
bool xml_parser(xml_t *doc, char *content);
void xml_add_data(xml_t *doc, xml_node_t **current, size_t *index, char *buf);
size_t xml_get_node_inner_text(xml_node_t *node, char *buf);
size_t xml_get_node_tag(xml_node_t *node, char *buf);
xml_t *xml_new(char *tag);
char *xml_str(xml_t *doc);
xml_node_t *xml_get_node_by_tag(xml_node_t *node, char *tag);
void xml_add_node(xml_node_t *node, xml_node_t *new_node);

char *serialize_node(xml_node_t *node);
xml_file_t *xml_file_open(char *path, int flags, bool buff);
void xml_file_close(xml_file_t *file);
