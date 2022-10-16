/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** get_arguments_function
*/

#include "../include/corewar.h"

func_size_t *get_func_arg2(int tmp, func_size_t *func_size)
{
    if (tmp & 32) {
        func_size->arg[1] = 'd';
        if (tmp & 16)
            func_size->arg[1] = 'i';
    } else
        func_size->arg[1] = 'r';
    if (tmp & 8) {
        func_size->arg[2] = 'd';
        if (tmp & 4)
            func_size->arg[2] = 'i';
    } else
        func_size->arg[2] = 'r';
    if (tmp & 2) {
        func_size->arg[3] = 'd';
        if (tmp & 1)
            func_size->arg[3] = 'i';
    } else
        func_size->arg[3] = 'r';
    return (func_size);
}

func_size_t *get_func_arg(int bitmask)
{
    if (bitmask == 0)
        return (NULL);
    int tmp = bitmask;
    func_size_t *func_size = malloc(sizeof(func_size_t));

    for (int i = 0; i < 4; i++)
        func_size->arg[i] = '\0';
    func_size == NULL ? exit(84) : 0;
    if (bitmask < 128) {
        tmp = bitmask + 128;
        func_size->arg[0] = 'r';
    } else {
        func_size->arg[0] = 'd';
        if (tmp & 64)
            func_size->arg[0] = 'i';
    }
    return (get_func_arg2(tmp, func_size));
}

int get_arg(func_size_t *func_arg, int function, FILE *ptr)
{
    int arg_size = 0;
    int dir_size = 2;
    int nbr_args = op_tab[function].nbr_args;
    int arg = 0;

    if (func_arg == NULL)
        return (get_arg_alone(function, ptr));
    for (int i = 0; i < nbr_args; i++) {
        dir_size = 2;
        if (function == 0 || function == 1 || function == 6 ||
        function == 7 || function == 8)
            dir_size = DIR_SIZE;
        if (func_arg->arg[i] == 'r') {
            arg_size += T_REG;
            fread(&arg, 1, T_REG, ptr);
        }
        if (func_arg->arg[i] == 'd') {
            arg_size += dir_size;
            fread(&arg, 1, dir_size, ptr);
        }
        if (func_arg->arg[i] == 'i') {
            arg_size += IND_SIZE;
        }
        arg = 0;
    }
    return (arg_size);
}
