/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_aff
*/

#include "../../include/corewar.h"

void execute_aff(corewar_t *g, champions_t *champ)
{
    u_char value = 0;
    if (champ->instru[0].rid != 'r')
        return;
    value = (char)champ->registre[champ->instru[0].value - 1];
    my_putchar(value);
    g = g;
}
