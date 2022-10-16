/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int negative = 0;

    if (str[0] == '-')
        negative = 1;
    else
        negative = 0;
    for (int i = 0 + negative; i < my_strlen(str); i++)
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - '0');
        else
            break;
    if (negative)
        nb = nb * -1;
    return (nb);
}
