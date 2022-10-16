/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** my_memset
*/

#include "../include/my.h"

void *my_memset(void *to_set, int character, size_t n)
{
    char *str = to_set;
    unsigned char chara = character;

    while (n--)
        *str++ = chara;
    return (to_set);
}
