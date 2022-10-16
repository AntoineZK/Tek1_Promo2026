/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;
    for (; src[j] != '\0'; j++, i++)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}
