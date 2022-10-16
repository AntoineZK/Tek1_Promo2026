/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** my_strncpy
*/

#include "../include/my.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    for (; i != n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
