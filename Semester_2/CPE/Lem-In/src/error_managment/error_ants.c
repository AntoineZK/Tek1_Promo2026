/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** error_ants
*/

#include "lemin.h"

int error_ants(char *str)
{
    if (check_nbr_arg(str, ' ') != 1)
        return (1);
    if (my_is_num(str, ' ') == 0)
        return (1);
    if (my_getnbr(str) == 0)
        return (1);
    return (0);
}
