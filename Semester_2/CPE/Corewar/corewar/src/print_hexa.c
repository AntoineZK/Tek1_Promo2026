/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** print_hexa
*/

#include "../include/corewar.h"

int decimal_to_hexa(int decimal)
{
    int i = 0;
    int hexa = 0;
    char *buffer = malloc(sizeof(char) * (my_int_len(decimal) + 1));

    for (; decimal != 0; i++) {
        buffer[i] = (decimal % 16) + '0';
        decimal /= 16;
    }
    buffer[i] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] > '9')
            buffer[i] += 7;
        hexa = hexa * 10 + (buffer[i] - '0');
    }
    my_revstr(buffer);
    my_putstr(buffer);
    return (0);
}

void print_hexa(int value)
{
    if (value == 0) {
        my_putstr("00");
        return;
    }
    if (value < 16) {
        my_putchar('0');
    }
    decimal_to_hexa(value);
}
