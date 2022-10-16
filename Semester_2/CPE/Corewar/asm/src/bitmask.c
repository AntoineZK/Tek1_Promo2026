/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** bitmask
*/

#include "../include/asm.h"
#include <stdlib.h>

static char *get_param_type(asm_list_t *list)
{
    char *arg = malloc(MAX_ARGS_NUMBER);

    if (arg == NULL)
        return (NULL);
    arg = my_memset(arg, 0, MAX_ARGS_NUMBER);
    if (list->asm_line.nbr_args == 1 && list->asm_line.type[0] != 1) {
        free(arg);
        return (NULL);
    }
    for (int i = 0; i != list->asm_line.nbr_args; i++) {
        if (check_type(list->tab[list->pos + i + 1]) == REG_SIZE)
            arg[i] = 'r';
        if (check_type(list->tab[list->pos + i + 1]) == DIR_SIZE)
            arg[i] = 'd';
        if (check_type(list->tab[list->pos + i + 1]) == IND_SIZE)
            arg[i] = 'i';
    }
    return (arg);
}

void get_bytemask(asm_list_t *list, int core)
{
    unsigned char bitmask = 0;
    char *arg = get_param_type(list);

    if (arg == NULL)
        return;
    for (int i = 0; i != MAX_ARGS_NUMBER; i++) {
        bitmask = bitmask << 2;
        if (arg[i] == 'r')
            bitmask += 1;
        if (arg[i] == 'd')
            bitmask += 2;
        if (arg[i] == 'i')
            bitmask += 3;
    }
    write(core, &bitmask, sizeof(char));
    free(arg);
    return;
}
