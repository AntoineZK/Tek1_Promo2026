/*
** EPITECH PROJECT, 2021
** my_get nbr
** File description:
** get number by parsing
*/

#include "../include/my.h"

int my_getnbr(char const *str)
{
    int number = 0;
    int sign = 1;
    int i = 0;

    if (*str == '\0')
        return (0);
    for (; str[i] != '\0'; ++i) {
        if (str[i] == '-'){
            sign = sign * -1;
        }
        if (str[i] >= '0' && str[i] <= '9'){
            number = number * 10 + str[i] - '0';
        }
        if (str[i] >= 'A' && str[i] <= 'z'){
            break;
        }
        if (number > 32767){
            return (0);
        }
    } return (sign * number);
}
