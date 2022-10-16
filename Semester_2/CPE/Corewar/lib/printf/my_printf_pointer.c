/*
** EPITECH PROJECT, 2021
** sources/my_printf_pointer
** File description:
** check your malloc!
*/

#include "../../include/my.h"
#include "../../include/printf.h"

void my_print_pointer(void *p, unsigned int *size)
{
    *size += my_putstr("0x");
    my_put_hexa((long) p, size);
}
