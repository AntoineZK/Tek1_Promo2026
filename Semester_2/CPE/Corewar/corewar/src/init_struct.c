/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** init_struct
*/

#include "../include/corewar.h"

u_char *set_null_value(u_char *value, int size)
{
    for (int i = 0; i < size; i++)
        value[i] = 0;
    return (value);
}

corewar_t *init_struct(corewar_t *g)
{
    g->header = malloc(sizeof(vm_header_t));
    if (g->header == NULL)
        return (NULL);
    g->header = my_memset(g->header, 0, sizeof(vm_header_t));
    g->header->name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
    if (g->header->name == NULL)
        return (NULL);
    g->header->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));
    if (g->header->comment == NULL)
        return (NULL);
    g->champ = NULL;
    g->vm = malloc(sizeof(char) * MEM_SIZE);
    if (g->vm == NULL)
        return (NULL);
    g->vm = set_null_value(g->vm, MEM_SIZE);
    g->cycle_to_die = CYCLE_TO_DIE;
    g->cycle_delta = CYCLE_DELTA;
    g->nb_live = 0;
    g->last_number = -1;
    g->last_name = NULL;
    return (g);
}
