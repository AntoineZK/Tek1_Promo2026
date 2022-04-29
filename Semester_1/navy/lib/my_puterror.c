/*
** EPITECH PROJECT, 2021
** my_puterror
** File description:
** put a string like my_putchar but for a error
*/

#include "../include/my.h"

int my_puterror(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
    return (0);
}
