/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_atoi
*/

#include "../include/my.h"

int my_atoi(char const *str)
{
    int nb = 0;
    int negative = 0;

    if (str[0] == '-')
        negative = 1;
    else
        negative = 0;
    for (int i = 0 + negative; i < my_strlen(str); i++)
        nb = nb * 10 + str[i] - '0';
    if (negative)
        nb = nb * -1;
    return (nb);
}
