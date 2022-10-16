/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** free_all
*/

#include "../include/corewar.h"

void free_all(corewar_t *g)
{
    free_arg(g->list);
    free_champ(g->champ);
    free_header(g->header);
    free(g->last_name);
    free(g->vm);
    free(g);
}
