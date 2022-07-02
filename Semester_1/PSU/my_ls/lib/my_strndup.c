/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strndup
*/

#include "my.h"

char *my_strndup(char *src, int n)
{
    char *dest = malloc(sizeof(char) * (n + 1));

    if (dest == NULL)
        return (NULL);
    my_strncpy(dest, src, n);
    return (dest);
}