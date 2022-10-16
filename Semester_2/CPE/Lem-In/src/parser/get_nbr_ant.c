/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** get_nbr_ant
*/

#include "lemin.h"

int get_nbr_ants(lemin_t *g)
{
    if (check_nbr_arg(g->d_map[0], ' ') && my_is_num(g->d_map[0], ' '))
        g->nb_ants = my_getnbr(g->d_map[0]);
    else
        return (84);
    return (0);
}
