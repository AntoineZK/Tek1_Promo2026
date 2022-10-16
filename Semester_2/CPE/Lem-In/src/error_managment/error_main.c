/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** error main file
*/

#include "lemin.h"

int error_mngt(char **str)
{
    if (error_ants(str[0]) == 1)
        return (1);
    if (error_rooms(str) == 1)
        return (1);
    return (0);
}
