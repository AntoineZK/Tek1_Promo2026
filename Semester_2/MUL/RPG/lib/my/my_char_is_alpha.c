/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_char_is_alpha
*/

#include "my.h"

int is_alpha(char **content)
{
    char c = *(*content);
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    (*content)++;
    return (0);
}

int my_char_is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}
