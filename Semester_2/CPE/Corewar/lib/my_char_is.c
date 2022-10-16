/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_char_is
*/

#include "../include/my.h"

int my_char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_char_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int my_char_is_alpha_sup(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_char_is_alpha_inf(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_char_is_alnum(char c)
{
    if (my_char_is_alpha(c) || my_char_is_num(c))
        return (0);
    return (1);
}
