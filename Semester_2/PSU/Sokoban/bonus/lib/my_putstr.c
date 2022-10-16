/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** my_putstr
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int len_word = my_strlen(str);

    write(1, str, len_word);
    return (0);
}
