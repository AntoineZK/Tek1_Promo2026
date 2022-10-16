/*
** EPITECH PROJECT, 2022
** int to char
** File description:
** my_int_to_char
*/

#include "../include/my.h"

int count_nb(int nb)
{
    int i = 10;
    int count = 1;

    for (; (nb / i) >= 1; i *= 10, count++);
    return (count);
}

char *int_to_char(int nb)
{
    int size = count_nb(nb);
    char *str = malloc(sizeof(char) * size + 1);

    if (str == NULL)
        return (NULL);
    str[size] = '\0';
    for (; size--; nb /= 10)
        str[size] = nb % 10 + '0';
    return (str);
}
