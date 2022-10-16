/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** get_arg_sec
*/

#include "../include/tetris.h"

int get_quit_key(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-q", "--key-quit=") == 1 && av[i + 1] != NULL) {
        if (my_isnum(av[i + 1]) == 1) {
            g->key_quit = my_getnbr(av[i + 1]);
            return (0);
        }
        return (84);
    }
    if (check_flag(av[i], "-q", "--key-quit=") == 2) {
        av[i] += 11;
        if (my_isnum(av[i]) == 1) {
            g->key_quit = my_getnbr(av[i]);
            return (0);
        }
        return (84);
    }
    return (84);
}

int get_pause_key(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-p", "--key-pause=") == 1 && av[i + 1] != NULL) {
        if (my_isnum(av[i + 1]) == 1) {
            g->key_pause = my_getnbr(av[i + 1]);
            return (0);
        }
        return (84);
    }
    if (check_flag(av[i], "-p", "--key-pause=") == 2) {
        av[i] += 12;
        if (my_isnum(av[i]) == 1) {
            g->key_pause = my_getnbr(av[i]);
            return (0);
        }
        return (84);
    }
    return (84);
}

int get_map_size(tetris_t *g, char **av, int i)
{
    av[i] += 11;
    int nb = 0;
    int j = 0;
    for (; av[i][j] != ','; j++) {
        if (av[i][j] > '9' || av[i][j] < '0')
            return (84);
        nb = nb * 10 + av[i][j] - '0';
    }
    g->line = nb;
    av[i] += j;
    if (my_isnum(av[i]) == 0)
        return (84);
    g->col = my_getnbr(av[i]);
    return (0);
}

int get_without_next(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-w", "--without-next") == 1) {
        g->hide = TRUE;
        return (0);
    }
    if (check_flag(av[i], "-w", "--without-next") == 2) {
        g->hide = TRUE;
        return (0);
    }
    return (84);
}

int get_debug(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-D", "--debug") == 1) {
        g->debug = TRUE;
        return (0);
    }
    if (check_flag(av[i], "-D", "--debug") == 2) {
        g->debug = TRUE;
        return (0);
    }
    return (84);
}
