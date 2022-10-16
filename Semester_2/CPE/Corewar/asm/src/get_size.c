/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** get_size.c
*/

#include "../include/asm.h"

static int special_size(asm_list_t *list, char **tab)
{
    int i = 0;

    if (list->asm_line.code == 10)
        return (6);
    if (list->asm_line.code == 9 || list->asm_line.code == 12)
        return (3);
    if (list->asm_line.code == 1)
        return (5);
    i++;
    for (int j = 0; j != list->asm_line.nbr_args; j++) {
        if (check_type(tab[list->pos + j + 1]) == 1)
            i++;
        else
            i += 2;
    }
    return (i);
}

static int get_size_line(asm_list_t *list)
{
    if (!(list->asm_line.nbr_args == 1 && list->asm_line.type[0] != 1))
        list->size++;
    if ((list->asm_line.code >= 9 && list->asm_line.code <= 12) ||
    list->asm_line.code == 1)
        list->size += special_size(list, list->tab);
    else {
        list->size++;
        for (int j = 0; j != list->asm_line.nbr_args; j++)
            list->size += check_type(list->tab[list->pos + j + 1]);
    }
    return (list->size);
}

int get_size_prog(asm_list_t *list)
{
    int size = 0;
    asm_list_t *backup = list;

    for (; list != NULL; list = list->next) {
        if (list->good == 1)
            size += get_size_line(list);
    }
    list = backup;
    size = __builtin_bswap32(size);
    return (size);
}

static int special_size_elem(char *word, int type)
{
    int i = 0;

    if (type == 9 || type == 12)
        return (2);
    if (type == 1)
        return (4);
    if (check_type(word) == 1)
        i = 1;
    else
        i = 2;
    return (i);
}

int get_size_elem(char *word, int type)
{
    int i = 0;

    if ((type >= 9 && type <= 12) || type == 1)
        return (special_size_elem(word, type));
    else
        i = check_type(word);
    return (i);
}
