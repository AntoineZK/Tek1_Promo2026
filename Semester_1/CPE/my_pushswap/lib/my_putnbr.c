/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_putnbr
*/

#include "my.h"

void my_putnbr_int(int number)
{
    if (number < 0) {
        number = -number;
        my_putstr("-");
    }
    if (number >= 0 && number <= 9) {
        my_putchar('0' + number);
    } else {
        my_putnbr_int(number / 10);
        my_putnbr_int(number % 10);
    }
}

void my_putnbr_float(float value)
{
    int integer = (int )value;
    float decimal = value - integer;

    my_putnbr_int(integer);
    my_putchar('.');
    my_putnbr_int((int) (decimal * 10));
}
