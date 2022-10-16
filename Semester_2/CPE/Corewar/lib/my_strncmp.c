/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strncmp
*/

#include "../include/my.h"

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i]) {
            return (0);
        }
    }
    return (1);
}
