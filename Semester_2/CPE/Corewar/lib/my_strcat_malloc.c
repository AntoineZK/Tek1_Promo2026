/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** well, real programmers use ed
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strcat_malloc(char *dest, char const *src)
{
    if (dest == NULL || src == NULL)
        return (NULL);
    int i = 0;
    int j = 0;
    int size = my_strlen(dest) + my_strlen(src) + 1;
    char *final_str = malloc(sizeof(char) * size);

    if (final_str == NULL)
        return (NULL);
    for (; dest[i] != '\0'; i++)
        final_str[i] = dest[i];
    free(dest);
    for (; src[j] != '\0'; j++, i++)
        final_str[i] = src[j];
    final_str[i] = '\0';
    dest = final_str;
    return (final_str);
}
