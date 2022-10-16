/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char const *src)
{
    char *copy = malloc(sizeof(char) * my_strlen(src) + 1);
    for (int i = 0; src[i] != '\0'; ++i)
        copy[i] = src[i];
    copy[my_strlen(src)] = '\0';
    return (copy);
}

void my_strcpy_dyn(char **dest, char const *src)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(*dest) +
    my_strlen(src) + 1));
    int i = 0;

    for (; src[i] != '\0'; ++i)
        new_str[i] = src[i];
    new_str[i] = '\0';
    free(*dest);
    (*dest) = new_str;
}
