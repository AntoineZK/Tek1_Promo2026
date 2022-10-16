/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_sub
*/

#include "../../include/corewar.h"

void sous_instru(champions_t *champ)
{
    champ->registre[champ->instru[2].value - 1] =
    champ->registre[champ->instru[0].value - 1] -
    champ->registre[champ->instru[1].value - 1];
}

void execute_sub(corewar_t *g, champions_t *champ)
{
    champ->carry = 0;
    if (champ->instru[0].rid != 'r' || champ->instru[1].rid != 'r' ||
    champ->instru[2].rid != 'r')
        return;
    sous_instru(champ);
    champ->carry = 1;
    g = g;
}
