/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** memory_writing
*/

#include "../include/corewar.h"

void write_char_in_mem(corewar_t *g, champions_t *champ,
u_char *value, int size)
{
    for (int i = 0; i <= size; i++) {
        g->vm[champ->head] = value[i];
        champ->head++;
        if (champ->head == MEM_SIZE)
            champ->head = 0;
    }
}

u_char read_char_in_mem(corewar_t *g, champions_t *champ)
{
    u_char value;

    value = g->vm[champ->head];
    champ->head++;
    if (champ->head == MEM_SIZE)
        champ->head = 0;
    return (value);
}

int read_dir_in_mem(corewar_t *g, champions_t *champ)
{
    int value = 0;

    for (int i = 0; i < 4; i++) {
        value = value << 8;
        value += read_char_in_mem(g, champ);
    }
    return (value);
}

int read_ind_in_mem(corewar_t *g, champions_t *champ)
{
    int value = 0;

    for (int i = 0; i < 2; i++) {
        value = value << 8;
        value += read_char_in_mem(g, champ);
    }
    return (value);
}
