/*
** EPITECH PROJECT, 2022
** my_putstr
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
