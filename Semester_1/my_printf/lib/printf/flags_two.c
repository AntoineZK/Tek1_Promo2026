/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** flags_two
*/

#include "../../include/printf.h"

void percent_f(va_list arglist)
{
    my_putnbr_float(va_arg(arglist, double));
}

void percent_e(va_list arglist)
{
    my_puterror(va_arg(arglist, char *));
}

void percent_u(va_list arglist)
{
    my_putnbr_uint(va_arg(arglist, unsigned int));
}

void percent_l(va_list arglist, char *str, int i)
{
    if (str[i] == 'd' || str[i] == 'i')
        my_putnbr_long(va_arg(arglist, long));
    if (str[i] == 'u') {
        my_putnbr_ulong(va_arg(arglist, unsigned long));
    }
}

void percent_h(va_list arglist, char *str, int i)
{
    if (str[i] == 'd' || str[i] == 'i')
        my_putnbr_short(va_arg(arglist, int));
    if (str[i] == 'u') {
        my_putnbr_ushort(va_arg(arglist, unsigned int));
    }
}
