/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** flags_two
*/

#include "printf.h"

void percent_f(va_list arglist)
{
    my_putnbr_float(va_arg(arglist, double));
}

void percent_e(va_list arglist)
{
    my_puterror(va_arg(arglist, char *));
}
