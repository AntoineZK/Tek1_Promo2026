/*
** EPITECH PROJECT, 2022
** my_int_len
** File description:
** my_int_len
*/

#include "../include/my.h"

int my_int_len(int number)
{
    int nb_div = 1;
    int result = 1;

    while (number / nb_div >= 1) {
        nb_div = nb_div * 10;
        result = result + 1;
    }
    return (result);
}
