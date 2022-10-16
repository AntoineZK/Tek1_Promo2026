/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** pars_linked_list.c
*/

#include "../include/asm.h"

static void compare_mnemonique(char **line, int i, int j, asm_list_t *list)
{
    if (my_strcmp(op_tab[i].mnemonique, line[j])) {
        list->asm_line = op_tab[i];
        list->pos = j;
        list->good = 1;
    }
}

static int pars_code(asm_list_t *list)
{
    int j = 0;

    list->tab = my_spliter(list->line, ' ');
    list->pos = -1;
    if (list->tab == NULL)
        return (EXIT_ERR);
    for (int i = 0; list->pos == -1 && list->tab[j] != NULL; i++) {
        if (op_tab[i].nbr_args == 0) {
            i = 0;
            j++;
        }
        if (list->tab[j] != NULL)
            compare_mnemonique(list->tab, i, j, list);
    }
    if (list->pos == -1)
        list->good = 0;
    return (0);
}

int pars_code_list(asm_list_t *list)
{
    asm_list_t *backup = list;

    for (; list != NULL; list = list->next)
        pars_code(list);
    list = backup;
    return (0);
}
