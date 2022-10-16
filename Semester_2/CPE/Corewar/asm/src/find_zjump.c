/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** find_zjump.c
*/

#include "../include/asm.h"

static int compute_size(asm_list_t *list, int first, int second)
{
    int size = 0;

    for (int i = 0; i != first; i++)
        list = list->next;
    for (int j = 0; (j + first) != second; j++) {
        size += list->size;
        list = list->next;
    }
    return (size);
}

int zjump_size(asm_list_t *list, asm_list_t *zjump, char *word)
{
    asm_list_t *backup = list;
    int elem1 = search_list_char(list, word);
    int elem2 = 0;
    int result = 0;

    for (; list != zjump; list = list->next)
        elem2++;
    list = backup;
    if (elem1 > elem2)
        result = (compute_size(list, elem2, elem1));
    else
        result = (compute_size(list, elem1, elem2) * -1);
    list = backup;
    return (result);
}
