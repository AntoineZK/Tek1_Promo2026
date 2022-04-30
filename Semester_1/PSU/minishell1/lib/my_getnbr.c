/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** my_getnbr
*/

#include "../include/my.h"

int my_getnbr(char const *str)
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