/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_live
*/

#include "../../include/corewar.h"

void execute_live(corewar_t *g, champions_t *champ)
{
    my_printf("The player %d(%s)is alive\n", champ->number, champ->name);
    if (g->last_name != NULL)
        free(g->last_name);
    g->last_name = my_strcpy_malloc(g->last_name, champ->name);
    g->last_number = champ->number;
    champ->alive = 1;
    champ->cycle_to_die = 0;
    g->nb_live--;
    if (g->nb_live <= 0) {
        g->cycle_to_die -= CYCLE_DELTA;
        g->nb_live = NBR_LIVE;
    }
}
