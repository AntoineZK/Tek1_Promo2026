/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}
