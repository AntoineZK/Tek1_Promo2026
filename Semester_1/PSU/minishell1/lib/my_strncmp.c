/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** my_strncmp
*/

#include "../include/my.h"

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    int result = 0;

    for (int i = 0; i != n; i++) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            return (result);
        }
    }
    return (0);
}
