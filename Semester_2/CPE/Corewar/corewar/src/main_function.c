/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** main_function
*/

#include "../include/corewar.h"

static func_ptn_t func_pointer[16] = {
    {execute_live},
    {execute_ld},
    {execute_st},
    {execute_add},
    {execute_sub},
    {execute_and},
    {execute_or},
    {execute_xor},
    {execute_zjmp},
    {execute_ldi},
    {execute_sti},
    {execute_fork},
    {execute_lld},
    {execute_lldi},
    {execute_lfork},
    {execute_aff}
};

void execute_function(champions_t *champ, corewar_t *g)
{
    if (champ->instruction < 0 || champ->instruction > 16)
        return;
    func_pointer[champ->instruction].ptr_fct(g, champ);
}
