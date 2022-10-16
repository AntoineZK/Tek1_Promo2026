/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_lld
*/

#include "../../include/corewar.h"

void execute_lld(corewar_t *g, champions_t *champ)
{
    int value = 0;

    champ->carry = 0;
    if (champ->instru[0].rid == 'r')
        return;
    if (champ->instru[1].rid != 'r')
        return;
    if (champ->instru[0].rid == 'd') {
        value = champ->instru[0].value;
        champ->registre[champ->instru[1].value - 1] = value;
    }
    if (champ->instru[0].rid == 'i') {
        value = champ->instru[0].value;
        champ->tail = champ->head;
        champ->registre[champ->instru[1].value - 1] =
        g->vm[(champ->head + value) % MEM_SIZE];
    }
    champ->carry = 1;
}
