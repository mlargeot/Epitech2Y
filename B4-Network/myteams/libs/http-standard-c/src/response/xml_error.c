/*
** EPITECH PROJECT, 2024
** bac-a-sable
** File description:
** xml_error
*/

#include <xml.h>
#include <status_code.h>
#include <utils.h>

xml_t *xml_error(status_code_t code, char *msg)
{
    xml_t *xml = xml_new("error");

    xml_new_node(xml->root, "code", get_status_message(code));
    xml_new_node(xml->root, "message", msg);
    return xml;
}
