/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** get_arg
*/

#include "../include/corewar.h"

int get_argument_alone(int function, champions_t *champ, corewar_t *g)
{
    int dir_size = DIR_SIZE;
    if (function >= 8 && function <= 11)
        dir_size = IND_SIZE;
    if (op_tab[function].type[0] == T_DIR && dir_size == DIR_SIZE)
        champ->instru[0].value = read_dir_in_mem(g, champ);
    if (op_tab[function].type[0] == T_DIR && dir_size == IND_SIZE)
        champ->instru[0].value = read_ind_in_mem(g, champ);
    if (op_tab[function].type[0] == T_REG)
        champ->instru[0].value = (int)read_char_in_mem(g, champ);
    if (op_tab[function].type[0] == T_IND)
        champ->instru[0].value = read_ind_in_mem(g, champ);
    return (0);
}

int get_argument(func_size_t *func_arg, int function,
champions_t *champ, corewar_t *g)
{
    int dir_size = DIR_SIZE;
    if (function < 0 || function > 16)
        return (84);
    int nbr_args = op_tab[function].nbr_args;
    int arg = 0;
    if (func_arg == NULL)
        return (get_argument_alone(function, champ, g));
    if (function >= 8 && function <= 11)
        dir_size = IND_SIZE;
    for (int i = 0; i < nbr_args; i++) {
        champ->instru[i].rid = func_arg->arg[i];
        if (func_arg->arg[i] == 'r')
            champ->instru[i].value = (int)read_char_in_mem(g, champ);
        if (func_arg->arg[i] == 'd' && dir_size == DIR_SIZE)
            champ->instru[i].value = read_dir_in_mem(g, champ);
        if (func_arg->arg[i] == 'd' && dir_size == IND_SIZE)
            champ->instru[i].value = read_ind_in_mem(g, champ);
        if (func_arg->arg[i] == 'i')
            champ->instru[i].value = read_ind_in_mem(g, champ);
    }
    return (arg);
}
