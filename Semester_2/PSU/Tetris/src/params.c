/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** params
*/

#include "tetris.h"

int check_flag(char *arg, char *small, char *full)
{
    if (my_strcmp(arg, small) == 1)
        return (1);
    for (int i = 0; full[i]; i++) {
        if (full[i] != arg[i])
            return (0);
    }
    return (2);
}

int add_param_sec(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-q", "--key-quit=") != 0)
        return (get_quit_key(g, av, i));
    if (check_flag(av[i], "-p", "--key-pause=") != 0)
        return (get_pause_key(g, av, i));
    if (check_flag(av[i], "-thisisaplaceholder", "--map-size=") != 0)
        return (get_map_size(g, av, i));
    if (check_flag(av[i], "-w", "--without-next") != 0)
        return (get_without_next(g, av, i));
    if (check_flag(av[i], "-D", "--debug") != 0)
        return (get_debug(g, av, i));
    if (check_flag(av[i], "-thisisaplaceholder", "--help") != 0) {
        g->help = TRUE;
        return (0);
    }
    return (0);
}

int add_param(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-L", "--level=") != 0)
        return (get_level(g, av, i));
    if (check_flag(av[i], "-l", "--key-left=") != 0)
        return (get_left_key(g, av, i));
    if (check_flag(av[i], "-r", "--key-right=") != 0)
        return (get_right_key(g, av, i));
    if (check_flag(av[i], "-t", "--key-turn=") != 0)
        return (get_turn_key(g, av, i));
    if (check_flag(av[i], "-d", "--key-drop=") != 0)
        return (get_drop_key(g, av, i));
    return (add_param_sec(g, av, i));
}
