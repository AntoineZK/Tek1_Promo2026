/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** my_puterror
*/

#include "../include/my.h"

int my_puterror(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
    return (0);
}
