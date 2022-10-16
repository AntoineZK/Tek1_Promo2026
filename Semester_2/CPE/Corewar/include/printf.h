/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#ifndef _MY_PRINTF_H_
    #define _MY_PRINTF_H_
void my_print_pointer(void *, unsigned int *size);
void my_printf_nbr(long nbr, unsigned int *size);
void my_put_base(unsigned int nb, char c, unsigned int *size);
int my_printf(char const *str, ...);
int my_put_hexa(long nb, unsigned int *size);
int my_put_hexa_maj(long nb, unsigned int *size);
int my_put_bin(unsigned long nb, unsigned int *size);
int my_put_oct(unsigned long nb, unsigned int *size);
#endif
