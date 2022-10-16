/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    char *new_str = malloc(sizeof(char) * \
    (my_strlen(dest) + my_strlen(src) + 1));

    for (int i = 0; dest[i]; i++)
        new_str[i] = dest[i];
    for (int i = 0; src[i]; i++)
        new_str[i + my_strlen(dest)] = src[i];
    new_str[my_strlen(dest) + my_strlen(src)] = '\0';
    return (new_str);
}
