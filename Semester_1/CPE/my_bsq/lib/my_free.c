/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** free
*/

#include "../include/free.h"

static free_t flags[3]  = {
    {'a', &free_darray},
    {'s', &free_str},
    {'t', &free_struct},
};

static void call_free(va_list arglist, char to_free)
{
    for (int i = 0; i <= 3; i++) {
        if (flags[i].to_free == to_free) {
            flags[i].func(arglist);
            return;
        }
    }
}

void my_free(char *str, ...)
{
    va_list arglist;

    va_start(arglist, str);
    for (int i = 0; str[i]; i++) {
        call_free(arglist, str[i]);
    }
    va_end(arglist);
}
