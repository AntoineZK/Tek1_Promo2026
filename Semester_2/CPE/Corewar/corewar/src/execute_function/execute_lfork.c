/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_lfork
*/

#include "../../include/corewar.h"

void execute_lfork(corewar_t *g, champions_t *champ)
{
    int adress = 0;
    fork_champ(champ);
    adress = (champ->head + champ->instru[0].value) % MEM_SIZE;
    champ = champ->next;
    champ->load_adress = adress;
    champ->head = adress;
    champ->tail = adress;
    champ->cycle_to_die = g->cycle_to_die;
    for (int i = 0; i < champ->prog_size; i++) {
        g->vm[(adress + i) % MEM_SIZE] = champ->code[i];
    }
    champ->head = champ->tail;
    advance_to_next_func(champ, g);
}
