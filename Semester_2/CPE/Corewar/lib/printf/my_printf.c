/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** rm -rf --no-preserve-root /
*/
#include <stdarg.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/printf.h"

int check_flag(va_list list, char c, unsigned int *size)
{
    if (c == 'o') {
        my_putstr("0");
        my_put_oct(va_arg(list, long), size);
    }
    if (c == 'x') {
        my_putstr("0x");
        my_put_hexa(va_arg(list, long), size);
    }
    if (c == 'X'){
        my_putstr("0X");
        my_put_hexa_maj(va_arg(list, long), size);
    }

    return (0);
}

void check_next(char c, va_list list, unsigned int *size)
{
    if (c == '%') {
        my_putchar('%');
        ++*size;
    }
    if (c == 'c') {
        my_putchar(va_arg(list, int));
        ++*size;
    }
    if (c == 's')
        *size += my_putstr(va_arg(list, char*));
    if (c == 'p')
        my_print_pointer(va_arg(list, void *), size);
    if (c == 'd' || c == 'i' || c == 'u')
        my_printf_nbr(va_arg(list, int), size);
    if (c == 'x' || c == 'X' || c == 'o' || c == 'b')
        my_put_base(va_arg(list, unsigned int), c, size);
    else
        check_flag(list, c, size);
}

int my_printf(char const *str, ...)
{
    va_list list;
    va_start(list, str);
    unsigned int size = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%' && str[i + 1] != ' ') {
            i++;
            check_next(str[i], list, &size);
        } else {
            ++size;
            my_putchar(str[i]);
        }
    }
    va_end(list);
    return (size);
}
