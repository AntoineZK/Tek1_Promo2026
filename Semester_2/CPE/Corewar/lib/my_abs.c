/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_abs
*/

#include "../include/my.h"

int my_abs(int nb)
{
    if (nb < 0) {
        return -(nb);
    } else {
        return nb;
    }
}
