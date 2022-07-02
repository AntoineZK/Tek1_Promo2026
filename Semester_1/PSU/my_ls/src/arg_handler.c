/*
** EPITECH PROJECT, 2022
** new_ls [WSL : Ubuntu-20.04]
** File description:
** arg_handler
*/

#include "general.h"

void activate_flag(char *arg, general_t *g)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        arg[i] == 'l' ? g->activated_flag[L] = 1 : 0;
        arg[i] == 'a' ? g->activated_flag[A] = 1 : 0;
    }
}

int arg_handling(int ac, char **av, general_t *g)
{
    int able = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && able == 0) {
            activate_flag(av[i], g);
            able = 1;
        }
        if (av[i][0] != '-') {
            g->list = add_node_last(g->list, av[i]);
        }
    }
    return (0);
}
