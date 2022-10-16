/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_and
*/

#include "../../include/corewar.h"

static int ret_value1(corewar_t *g, champions_t *champ, int value1)
{
    if (champ->instru[0].rid == 'r')
        value1 = champ->registre[champ->instru[0].value - 1];
    if (champ->instru[0].rid == 'd')
        value1 = champ->instru[0].value;
    if (champ->instru[0].rid == 'i')
        value1 = g->vm[(champ->head + champ->instru[0].value %
        IDX_MOD) % MEM_SIZE];
    return (value1);
}

static int ret_value2(corewar_t *g, champions_t *champ, int value2)
{
    if (champ->instru[1].rid == 'r')
        value2 = champ->registre[champ->instru[1].value - 1];
    if (champ->instru[1].rid == 'd')
        value2 = champ->instru[1].value;
    if (champ->instru[1].rid == 'i')
        value2 = g->vm[(champ->head + champ->instru[1].value %
        IDX_MOD) % MEM_SIZE];
    return (value2);
}

void execute_and(corewar_t *g, champions_t *champ)
{
    int value1 = 0;
    int value2 = 0;
    champ->carry = 0;

    if (champ->instru[2].rid != 'r')
        return;
    value1 = ret_value1(g, champ, value1);
    value2 = ret_value2(g, champ, value2);
    champ->registre[champ->instru[2].value - 1] = value1 & value2;
    champ->carry = 1;
    return;
}
