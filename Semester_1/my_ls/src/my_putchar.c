/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my_putchar
*/

#include "../include/my.h"
#include "../include/ls.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
