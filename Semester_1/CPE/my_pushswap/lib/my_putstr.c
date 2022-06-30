/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int len_word = my_strlen(str);

    if (write(1, str, len_word) == -1)
        return (84);
    return (0);
}

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (84);
    return (0);
}
