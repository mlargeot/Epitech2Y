/*
** EPITECH PROJECT, 2024
** B-NWP-400-REN-4-1-myteams-morgan.largeot
** File description:
** uuid
*/

#include <uuid/uuid.h>
#include <stdlib.h>

char *uuid_gen(char *dest)
{
    uuid_t binuuid;

    if (!dest)
        dest = malloc(37);
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, dest);
    return dest;
}
