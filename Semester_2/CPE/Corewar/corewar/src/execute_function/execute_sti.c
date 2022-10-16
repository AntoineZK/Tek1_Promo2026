/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_sti
*/

#include "../../include/corewar.h"

void execute_sti(corewar_t *g, champions_t *champ)
{
    int value1 = 0;
    int value2 = 0;

    if (champ->instru[0].rid != 'r' || champ->instru[2].rid == 'i')
        return;
    if (champ->instru[1].rid == 'r')
        value1 = champ->registre[champ->instru[1].value - 1];
    if (champ->instru[1].rid == 'd')
        value1 = champ->instru[1].value;
    if (champ->instru[1].rid == 'i')
        value1 = g->vm[(champ->head + champ->instru[1].value
        % IDX_MOD) % MEM_SIZE];
    if (champ->instru[2].rid == 'r')
        value2 = champ->registre[champ->instru[2].value - 1];
    if (champ->instru[2].rid == 'd')
        value2 = champ->instru[2].value;
    g->vm[(champ->head + ((value1 + value2) % IDX_MOD)) % MEM_SIZE] =
    champ->registre[champ->instru[0].value - 1];
}
