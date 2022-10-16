/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_int_len
*/

#include "../include/my.h"

int my_int_len(int number)
{
    int nb_div = 1;
    int result = 1;

    for (; number / nb_div >= 1; result++)
        nb_div = nb_div * 10;
    return (result);
}
