/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** main
*/

#include "general.h"

int main(int ac, char **av)
{
    general_t *g = malloc(sizeof(general_t));

    g = init_struct(g);
    if (ac == 1) {
        my_ls(av, g);
    } else {
        arg_handling(ac, av, g);
        use_flag(g);
        free_list(g->list);
    }
    my_free("ss", g->activated_flag, g);
    return (0);
}
