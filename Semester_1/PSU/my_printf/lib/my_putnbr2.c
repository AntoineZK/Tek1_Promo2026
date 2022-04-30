/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_put_nbr2
*/

#include "../include/my.h"

void my_putnbr_short(short number)
{
    if (number < 0) {
        number = -number;
        my_putchar('-');
    }
    if (number >= 0 && number <= 9) {
        my_putchar('0' + number);
    } else {
        my_putnbr_short(number / 10);
        my_putnbr_short(number % 10);
    }
}

void my_putnbr_ushort(unsigned short number)
{
    if (number <= 9) {
        my_putchar('0' + number);
    } else {
        my_putnbr_ushort(number / 10);
        my_putnbr_ushort(number % 10);
    }
}
