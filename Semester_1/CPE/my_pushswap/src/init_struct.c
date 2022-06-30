/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** init_struct
*/

#include "general.h"

lk_list *fill_list(lk_list *list, char **av)
{
    for (int i = 1; av[i]; i++) {
        if (my_str_is_num(av[i]) == 1) {
            list = add_node_last(list, av[i]);
        } else {
            return (NULL);
        }
    }
    return (list);
}

general_t *init_struct(general_t *g, char **av)
{
    g = my_memset(g, 0, sizeof(general_t));
    g->list = fill_list(g->list, av);
    if (g->list == NULL)
        return (NULL);
    return (g);
}
