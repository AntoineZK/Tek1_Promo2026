/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int negative = 0;
    while (str[i] == '+' || str[i] == '-')
        if (str[i] == '-')
            negative = !negative;
    for (; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9')
            break;
        nbr = nbr * 10 + (str[i] - 48);
    }
    if (negative)
        return (nbr * -1);
    return (nbr);
}
