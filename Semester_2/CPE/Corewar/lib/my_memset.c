/*
** EPITECH PROJECT, 2022
** memset
** File description:
** memset
*/

#include <stddef.h>

void *my_memset (void *dest, int val, size_t len)
{
    unsigned char *ptr = dest;
    while (len-- > 0)
        *ptr++ = val;
    return dest;
}
