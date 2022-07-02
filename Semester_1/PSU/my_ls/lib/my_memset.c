/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *to_set, int character, size_t len)
{
    char *str = to_set;
    unsigned char chara = character;

    while (len > 0) {
        *str = chara;
        str++;
        len--;
    }
    return (to_set);
}
