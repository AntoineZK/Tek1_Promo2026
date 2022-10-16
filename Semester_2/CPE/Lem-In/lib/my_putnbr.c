/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int my_putnbr(int number)
{
    if (number < 0) {
        number = -number;
        my_putstr("-");
    }
    if (number >= 0 && number <= 9) {
        my_putchar('0' + number);
    } else {
        my_putnbr(number / 10);
        my_putnbr(number % 10);
    }
    return (0);
}
