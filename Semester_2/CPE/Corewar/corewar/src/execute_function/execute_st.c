/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_st
*/

#include "../../include/corewar.h"

void execute_st(corewar_t *g, champions_t *champ)
{
    if (champ->instru[0].rid != 'r')
        return;
    if (champ->instru[1].rid == 'd')
        return;
    if (champ->instru[1].rid == 'r') {
        champ->registre[champ->instru[1].value - 1] =
        champ->registre[champ->instru[0].value - 1];
    }
    if (champ->instru[1].rid == 'i') {
        champ->tail = champ->head;
        g->vm[(champ->head + champ->instru[1].value % IDX_MOD) % MEM_SIZE] =
        champ->registre[champ->instru[0].value - 1];
    }
}
