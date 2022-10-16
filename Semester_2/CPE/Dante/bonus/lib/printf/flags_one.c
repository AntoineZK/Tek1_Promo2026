/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** flags_one
*/

#include "../../include/printf.h"

void percent_c(va_list arglist)
{
    my_putchar(va_arg(arglist, int));
}

void percent_d_i(va_list arglist)
{
    my_putnbr_int(va_arg(arglist, int));
}

void percent_s(va_list arglist)
{
    my_putstr(va_arg(arglist, char *));
}

void percent_a(va_list arglist)
{
    print_darray(va_arg(arglist, char **));
}

void percent(va_list arglist)
{
    my_putchar('%');
}
