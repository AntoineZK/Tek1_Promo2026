/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** xml_getter
*/

#include "utils/xml.h"

char *xml_get_value(char **content)
{
    int len = 0;
    for (; (*(*content)) != '\"' && (*(*content)) != '\'' &&
    (*(*content)) != '\0';)
        (*content)++;
    char separator = *(*content);
    (*content)++;
    for (; (*content)[len] != separator; len++);
    char *value = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; ++i)
        value[i] = (*content)[i];
    (*content) += len + 1;
    value[len] = 0;
    for (; (*(*content)) == ' '; (*content)++);
    return (value);
}

char *xml_get_param(char **content)
{
    int len = 0;
    for (; (*content)[len] != ' ' && (*content)[len] != '=' &&
    (*content)[len] != '\0';)
        len++;
    for (; (*(*content)) == ' '; (*content)++);
    char *name = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j < len; j++)
        name[j] = (*content)[j];
    name[len] = 0;
    (*content) += len;
    for (; (*(*content)) == ' '; (*content)++);
    return (name);
}
