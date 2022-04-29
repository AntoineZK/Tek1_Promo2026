/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** put a string like my_putchar but for a string
*/

#include "../include/my.h"
#include "../include/ls.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
