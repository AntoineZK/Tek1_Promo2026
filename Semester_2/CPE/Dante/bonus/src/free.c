/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** free
*/

#include "dante.h"

void free_all(dante_t *g)
{
    free_double_array(g->d_map);
    free(g->c_map);
    free(g);
}
