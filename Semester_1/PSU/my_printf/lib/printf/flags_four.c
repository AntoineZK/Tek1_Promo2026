/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** flags_five
*/

#include "../../include/printf.h"

static void hashtag_o(va_list arglist, char *buffer)
{
    int i = 0;
    int nb = va_arg(arglist, int);

    for (; nb != 0; i++) {
        buffer[i] = (nb % 8) + '0';
        nb /= 8;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    if (buffer[0] == '0' && my_strlen(buffer) == 1) {
        my_putchar('0');
    } else {
        my_putstr("0");
        my_putstr(buffer);
    }
    free(buffer);
}

static void hashtag_b(va_list arglist, char *buffer)
{
    int i = 0;
    int nb = va_arg(arglist, int);

    for (; nb != 0; i++) {
        buffer[i] = (nb % 2) + '0';
        nb /= 2;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    if (buffer[0] == '0' && my_strlen(buffer) == 1) {
        my_putchar('0');
    } else {
        my_putstr("0b");
        my_putstr(buffer);
    }
    free(buffer);
}

static void hashtag_x_maj(va_list arglist, char *buffer)
{
    int i = 0;
    int rest = 0;
    int nb = va_arg(arglist, int);

    for (; nb != 0; i++) {
        rest = nb % 16;
        buffer[i] = (rest >= 10) ? rest - 10 + 'A' : rest + '0';
        nb /= 16;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    if (buffer[0] == '0' && my_strlen(buffer) == 1)
        my_putchar('0');
    else {
        my_putstr("0X");
        my_putstr(buffer);
    }
    free(buffer);
}

static void hashtag_x_min(va_list arglist, char *buffer)
{
    int i = 0;
    int rest = 0;
    int nb = va_arg(arglist, int);

    for (; nb != 0; i++) {
        rest = nb % 16;
        buffer[i] = (rest >= 10) ? rest - 10 + 'a' : rest + '0';
        nb /= 16;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    if (buffer[0] == '0' && my_strlen(buffer) == 1)
        my_putchar('0');
    else {
        my_putstr("0x");
        my_putstr(buffer);
    }
    free(buffer);
}

void hashtag(va_list arglist, char *str, int i)
{
    char *buffer = malloc(sizeof(char) * 11);

    if (str[i] == 'b')
        hashtag_b(arglist, buffer);
    if (str[i] == 'X')
        hashtag_x_maj(arglist, buffer);
    if (str[i] == 'x')
        hashtag_x_min(arglist, buffer);
    if (str[i] == 'o')
        hashtag_o(arglist, buffer);
}
