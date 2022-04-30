/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strcat
*/

#include "../include/my.h"

void my_strcat(char **dest, char const *src)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(*dest)
    + my_strlen(src) + 1));
    int i = 0;
    for (; (*dest)[i] != '\0'; i++)
        new_str[i] = (*dest)[i];
    for (; src[i - my_strlen(*dest)] != '\0'; i++)
        new_str[i] = src[i - my_strlen(*dest)];
    new_str[i] = '\0';
    free(*dest);
    (*dest) = new_str;
}
