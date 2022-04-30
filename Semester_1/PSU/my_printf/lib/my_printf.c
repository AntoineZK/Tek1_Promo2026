/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_printf
*/

#include "../include/printf.h"

static printf_t flags[13]  = {
    {'d', &percent_d_i},
    {'i', &percent_d_i},
    {'s', &percent_s},
    {'c', &percent_c},
    {'a', &percent_a},
    {'f', &percent_f},
    {'e', &percent_e},
    {'o', &percent_o},
    {'b', &percent_b},
    {'x', &percent_x_min},
    {'X', &percent_x_maj},
    {'p', &percent_p},
    {'u', &percent_u},
};

static printf_two_t flags_two[3]  = {
    {'l', &percent_l},
    {'h', &percent_h},
    {'#', &hashtag},
};

static void call_percent(va_list arglist, char percent)
{
    if (percent == '%') {
        percent_percent();
        return;
    }
    for (int i = 0; i <= 13; i++) {
        if (flags[i].percent == percent) {
            flags[i].func(arglist);
            return;
        }
    }
}

static int call_percent_two(va_list arglist, char percent, char *str, int j)
{
    for (int i = 0; i <= 3; i++) {
        if (flags_two[i].percent == percent) {
            j++;
            flags_two[i].func(arglist, str, j);
            return (j);
        }
    }
    return (j);
}

static int condition_handler(va_list arglist, char *str, int i)
{
    if (str[i] == 'l' || str[i] == 'h' || str[i] == '#') {
        i = call_percent_two(arglist, str[i], str, i);
    } else {
        call_percent(arglist, str[i]);
    }
    return (i);
}

void my_printf(char *str, ...)
{
    va_list arglist;

    va_start(arglist, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            i = condition_handler(arglist, str, i);
        } else
            my_putchar(str[i]);
    }
    va_end(arglist);
}
