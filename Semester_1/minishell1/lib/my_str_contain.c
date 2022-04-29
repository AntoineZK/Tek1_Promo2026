/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** my_str_contain
*/

#include "../include/my.h"

int my_str_contain(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z') &&
        !((str[i] >= 'A' && str[i] <= 'Z')) &&
        (!(str[i] >= '0' && str[i] <= '9'))) {
            my_putstr("setenv: Variable name must contain");
            my_putstr(" alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}
