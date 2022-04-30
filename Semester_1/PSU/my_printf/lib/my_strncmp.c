/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strncmp
*/

#include "../include/my.h"

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    for (int i = 0; i != n; i++) {
        if (s1[i] != s2[i]) {
            return (1);
        }
    }
    return (0);
}
