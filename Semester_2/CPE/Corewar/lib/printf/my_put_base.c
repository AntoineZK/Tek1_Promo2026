/*
** EPITECH PROJECT, 2021
** my_put_base
** File description:
** man man
*/

#include "../../include/my.h"
#include "../../include/printf.h"

int my_put_hexa(long nb, unsigned int *size)
{
    int rem;
    if (nb == 0)
        return (0);
    rem = nb % 16;
    my_put_hexa((nb / 16), size);
    if (rem >= 10) {
        my_putchar(rem + 'W');
        *size += 1;
    } else {
        my_putchar(rem + '0');
        *size += 1;
    }

    return (*size);
}

int my_put_hexa_maj(long nb, unsigned int *size)
{
    int rem;
    if (nb == 0)
        return (0);
    rem = nb % 16;
    my_put_hexa_maj((nb / 16), size);
    if (rem >= 10) {
        my_putchar(rem + 55);
        *size += 1;
    } else {
        my_putchar(rem + '0');
        *size += 1;
    }

    return (*size);
}

int my_put_bin(unsigned long nb, unsigned int *size)
{
    if (nb / 2)
        my_put_bin((nb / 2), size);

    my_putchar(nb % 2 + '0');
    *size += 1;

    return (*size);
}

int my_put_oct(unsigned long nb, unsigned int *size)
{
    *size += 1;
    if (nb / 8)
        my_put_oct((nb / 8), size);

    my_putchar(nb % 8 + '0');
    return (*size);
}

void my_put_base(unsigned int nb, char c, unsigned int *size)
{
    if (c == 'o')
        *size = my_put_oct(nb, size);
    if (c == 'x')
        *size = my_put_hexa(nb, size);
    if (c == 'X')
        *size = my_put_hexa_maj(nb, size);
    if (c == 'b')
        *size = my_put_bin(nb, size);
    return;
}
