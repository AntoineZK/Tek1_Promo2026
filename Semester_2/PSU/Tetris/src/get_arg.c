/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** get_arg
*/

#include "../include/tetris.h"

int get_level(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-L", "--level=") == 1 && av[i + 1] != NULL) {
        if (my_isnum(av[i + 1]) == 1) {
            g->level = my_getnbr(av[i + 1]);
            return (0);
        }
        return (84);
    }
    if (check_flag(av[i], "-L", "--level=") == 2) {
        av[i] += 8;
        if (my_isnum(av[i]) == 1) {
            g->level = my_getnbr(av[i]);
            return (0);
        }
        return (84);
    }
    return (84);
}

int get_left_key(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-l", "--key-left=") == 1 && av[i + 1] != NULL) {
        if (my_isnum(av[i + 1]) == 1) {
            g->key_left = my_getnbr(av[i + 1]);
            return (0);
        }
        return (84);
    }
    if (check_flag(av[i], "-l", "--key-left=") == 2) {
        av[i] += 11;
        if (my_isnum(av[i]) == 1) {
            g->key_left = my_getnbr(av[i]);
            return (0);
        }
        return (84);
    }
    return (84);
}

int get_right_key(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-r", "--key-right=") == 1 && av[i + 1] != NULL) {
        if (my_isnum(av[i + 1]) == 1) {
            g->key_right = my_getnbr(av[i + 1]);
            return (0);
        }
        return (84);
    }
    if (check_flag(av[i], "-r", "--key-right=") == 2) {
        av[i] += 12;
        if (my_isnum(av[i]) == 1) {
            g->key_right = my_getnbr(av[i]);
            return (0);
        }
        return (84);
    }
    return (84);
}

int get_turn_key(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-t", "--key-turn=") == 1 && av[i + 1] != NULL) {
        if (my_isnum(av[i + 1]) == 1) {
            g->key_turn = my_getnbr(av[i + 1]);
            return (0);
        }
        return (84);
    }
    if (check_flag(av[i], "-t", "--key-turn=") == 2) {
        av[i] += 11;
        if (my_isnum(av[i]) == 1) {
            g->key_turn = my_getnbr(av[i]);
            return (0);
        }
        return (84);
    }
    return (84);
}

int get_drop_key(tetris_t *g, char **av, int i)
{
    if (check_flag(av[i], "-d", "--key-drop=") == 1 && av[i + 1] != NULL) {
        if (my_isnum(av[i + 1]) == 1) {
            g->key_drop = my_getnbr(av[i + 1]);
            return (0);
        }
        return (84);
    }
    if (check_flag(av[i], "-d", "--key-drop=") == 2) {
        av[i] += 11;
        if (my_isnum(av[i]) == 1) {
            g->key_drop = my_getnbr(av[i]);
            return (0);
        }
        return (84);
    }
    return (84);
}
