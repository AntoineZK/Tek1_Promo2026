/*
** EPITECH PROJECT, 2022
** my_put_error
** File description:
** my_put_error
*/

#include "../include/my.h"

int my_put_error(char const *str)
{
    int len_word = my_strlen(str);

    write(2, str, len_word);
    return (84);
}
