/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** my_put_nbr
*/

#include "../include/my.h"

int my_put_nbr(int number)
{
    if (number < 0) {
        number = -number;
        my_putchar('-');
    }
    if (number >= 0 && number <= 9) {
        my_putchar('0' + number);
    } else {
        my_put_nbr(number / 10);
        my_put_nbr(number % 10);
    }
    return (0);
}
