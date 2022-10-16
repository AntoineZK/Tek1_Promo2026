/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_intcpy
*/

#include "../include/my.h"

void my_intcpy(int *dest, char *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}
