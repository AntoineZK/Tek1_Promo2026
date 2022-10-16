/*
** EPITECH PROJECT, 2022
** my_memset
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *to_set, int character, size_t n)
{
    char *str = to_set;
    unsigned char chara = character;

    while (n--)
        *str++ = chara;
    return (to_set);
}
