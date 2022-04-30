/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** well, real programmers use ed
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (; dest[i]; i++);

    for (int j = 0; src[j]; j++, i++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
    return (dest);
}
