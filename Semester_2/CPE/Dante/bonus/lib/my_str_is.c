/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_str_is
*/

#include "../include/my.h"

int my_str_is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}

int my_str_is_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return (0);
    }
    return (1);
}

int my_str_is_alpha_sup(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
    }
    return (1);
}

int my_str_is_alpha_inf(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
    }
    return (1);
}
