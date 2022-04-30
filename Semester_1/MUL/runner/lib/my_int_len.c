/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** my_int_len
*/

#include "../include/my.h"

int my_int_len(int number)
{
    int nb_div = 1;
    int result = 1;

    for (;number / nb_div >= 1;) {
        nb_div = nb_div * 10;
        result = result + 1;
    }
    return (result);
}
