/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_printf
*/

#include "printf.h"

static printf_t flags[8]  = {
    {'d', &percent_d_i},
    {'i', &percent_d_i},
    {'s', &percent_s},
    {'c', &percent_c},
    {'%', &percent},
    {'a', &percent_a},
    {'f', &percent_f},
    {'e', &percent_e},
};

static void call_percent(va_list arglist, char percent)
{
    for (int i = 0; i <= 8; i++) {
        if (flags[i].percent == percent) {
            flags[i].func(arglist);
            return;
        }
    }
}

void my_printf(char *str, ...)
{
    va_list arglist;

    va_start(arglist, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            call_percent(arglist, str[i]);
        } else
            my_putchar(str[i]);
    }
    va_end(arglist);
}
