/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** place_champion
*/

#include "../include/corewar.h"

void revert_endianess(corewar_t *g, champions_t *champ)
{
    char tmp = 0;
    for (int i = champ->head; i <= champ->prog_size; i += 2) {
        tmp = g->vm[i];
        g->vm[i] = g->vm[i + 1];
        g->vm[i + 1] = tmp;
    }
}

void place_champion(corewar_t *g)
{
    int load_adress[g->nb_player];
    champions_t *tmp = g->champ;

    for (int i = 0; i < g->nb_player; i++) {
        load_adress[i] = MEM_SIZE / (g->nb_player) * i;
    }
    for (int i = 0; i < g->nb_player; i++) {
        tmp->load_adress = load_adress[i];
        tmp->head = load_adress[i];
        tmp->tail = load_adress[i];
        tmp->alive = 1;
        write_char_in_mem(g, tmp, tmp->code, tmp->prog_size);
        tmp->head = tmp->tail;
        tmp = tmp->next;
    }
}
