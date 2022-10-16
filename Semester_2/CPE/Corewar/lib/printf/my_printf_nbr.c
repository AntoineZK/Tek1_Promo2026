/*
** EPITECH PROJECT, 2021
** sources/my_print_nbr
** File description:
** epitech > 42
*/

#include "../../include/my.h"
#include "../../include/printf.h"

void my_printf_nbr(long n, unsigned int *size)
{
    ++*size;
    if (n < 0) {
        my_putchar('-');
        n *= -1 ;
    }
    if (n / 10)
        my_printf_nbr(n / 10, size);

    my_putchar(n % 10 + '0');
}
