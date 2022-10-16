/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "../include/corewar.h"

int check_alive_champ(corewar_t *g)
{
    champions_t *tmp = g->champ;
    int tmp2 = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->alive == 1) {
            tmp2 = tmp->number;
            break;
        }
    }
    tmp = g->champ;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->alive == 1 && tmp->number != tmp2)
            return (1);
    }
    return (0);
}

void dump_memory(corewar_t *g)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        print_hexa(g->vm[i]);
        if (i % 32 == 31)
            my_printf("\n");
    }
}

void virtual_machine(corewar_t *g)
{
    int cycle = 1;
    place_champion(g);
    for (champions_t *tmp = g->champ; tmp != NULL; tmp = tmp->next)
        advance_to_next_func(tmp, g);
    while (1) {
        if (cycle == g->nb_cycle)
            break;
        execute_champion(g);
        if (g->cycle_to_die <= 0)
            break;
        if (check_alive_champ(g) == 0)
            break;
        cycle++;
    }
    g->nb_cycle > 0 ? dump_memory(g) : 0;
    if (g->last_name == NULL)
        my_printf("No winner\n");
    else
        my_printf("The player %d(%s)has won\n", g->last_number,
        g->last_name);
}

void fill_champ(corewar_t *g)
{
    args_t *tmp = g->list;

    while (g->list != NULL) {
        find_header(g, g->list->name);
        add_champ(&g->champ, g->header, g->list);
        g->list = g->list->next;
    }
    g->list = tmp;
}

int main(int ac, char **argv)
{
    corewar_t *g = malloc(sizeof(corewar_t));
    int ret_value = 0;

    if (!g)
        return (84);
    g = my_memset(g, 0, sizeof(corewar_t));
    g->list = NULL;
    ret_value = arg_handler(g, ac, argv);
    if (ret_value == 84 || ret_value == 0) {
        free(g);
        return (ret_value);
    }
    g = init_struct(g);
    if (g == NULL) {
        free(g);
        return (84);
    }
    fill_champ(g);
    virtual_machine(g);
    free_all(g);
    return (0);
}
