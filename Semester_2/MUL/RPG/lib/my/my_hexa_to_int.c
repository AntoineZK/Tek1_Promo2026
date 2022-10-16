/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_hexa_to_int
*/

#include "my.h"

static int get_value(char c)
{
    if (my_char_is_alpha(c)) {
        if (c >= 'Z')
            return (c - 'a' + 10);
        else
            return (c - 'A' + 10);
    }
    return (c - '0');
}

int my_hexa_to_int(char const *str)
{
    int nb = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        nb = nb * 16 + get_value(str[i]);
    }
    return (nb);
}
