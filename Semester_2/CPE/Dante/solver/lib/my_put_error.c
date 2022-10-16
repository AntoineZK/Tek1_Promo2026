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

    if (write(2, str, len_word) == -1)
        return (84);
    return (84);
}
