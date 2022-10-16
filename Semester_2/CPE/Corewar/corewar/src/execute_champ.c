/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_champ
*/

#include "../include/corewar.h"

int get_func_type(champions_t *champ, corewar_t *g)
{
    int mnemomic = 0;

    mnemomic = (int)read_char_in_mem(g, champ);
    return (find_function(mnemomic));
}

int get_bitmask(champions_t *champ, corewar_t *g)
{
    int bitmask = 0;

    bitmask = (int)read_char_in_mem(g, champ);
    return (bitmask);
}

void advance_to_next_func(champions_t *champ, corewar_t *g)
{
    int bitmask = 0;
    func_size_t *func_size = NULL;
    for (int i = 0; i < 4; i++)
        champ->instru[i].value = 0;
    champ->instruction = get_func_type(champ, g);
    champ->cycles = op_tab[champ->instruction].nbr_cycles;
    if (champ->instruction == 0 || champ->instruction == 8
    || champ->instruction == 11 || champ->instruction == 14)
        bitmask = 0;
    else
        bitmask = get_bitmask(champ, g);
    func_size = get_func_arg(bitmask);
    get_argument(func_size, champ->instruction, champ, g);
    free(func_size);
}

void execute_champion(corewar_t *g)
{
    for (champions_t *tmp = g->champ; tmp != NULL; tmp = tmp->next) {
        if (tmp->alive == 0)
            continue;
        if (tmp->cycles == 0) {
            execute_function(tmp, g);
            advance_to_next_func(tmp, g);
        }
        if (tmp->cycle_to_die >= g->cycle_to_die) {
            tmp->alive = 0;
        }
        tmp->cycles > 0 ? tmp->cycles-- : 0;
        tmp->cycle_to_die++;
    }
}
