/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** get_data
*/

#include "lemin.h"

int check_nbr_arg(char *str, char sep)
{
    int count = 1;

    for (int i = 0; str[i]; i++) {
        if (str[i]  == sep && (str[i + 1] != sep && str[i + 1] != '\0'))
            count++;
    }
    return (count);
}

int get_data(lemin_t *g)
{
    int i = 0;

    if (error_mngt(g->d_map) == 1)
        return (84);
    if (get_nbr_ants(g) == 84)
        return (84);
    i = get_room(g);
    if (!check_start_end(g, START) || !check_start_end(g, END))
        return (84);
    if (check_repeat_name(g) >= 1) {
        return (84);
    }
    if (i == 84)
        return (84);
    if (init_tunnels(g, i) == 84)
        return (84);
    g->end = get_end(g);
    g->start = get_start(g);
    return (0);
}

int get_x(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            return (my_getnbr(str + i + 1));
    }
    return (0);
}

int get_y(char *str)
{
    int nb_space = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            nb_space++;
        if (nb_space == 2)
            return (my_getnbr(str + i + 1));
    }
    return (0);
}
