/*
** EPITECH PROJECT, 2021
** My_ls
** File description:
** my_strcomb
*/

#include "../include/my.h"

char *my_strcomb(char *fstr, char *lstr)
{
    char *str = malloc(sizeof(char) * (my_strlen(fstr) + my_strlen(lstr) + 2));
    int i = 0;
    for (; fstr[i]; i++)
        str[i] = fstr[i];
    str[i] = '/';
    i++;
    for (int j = 0; lstr[j]; j++) {
        str[i] = lstr[j];
        i++;
    }
    str[i] = '\0';
    return (str);
}
