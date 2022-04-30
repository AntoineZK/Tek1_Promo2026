/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** main
*/

#include "bsq.h"

bsq_t *init_struct(bsq_t *g, char *map)
{
    g = my_memset(g, 0, sizeof(bsq_t));
    g->c_map = stat_file(map);
    if (g->c_map == NULL) {
        my_free("st", g->c_map, g);
        return (NULL);
    }
    g->nb_line = my_atoi_bis(g->c_map);
    g->width = 1;
    g->height = 1;
    g->tmp = g->c_map;
    for (; *g->c_map != '\n'; g->c_map++);
    g->c_map++;
    for (; g->c_map[g->max_width] != '\n'; g->max_width++);
    g->d_map = my_stwa(g->c_map, '\n');
    if (!true_nbline(g)) {
        my_free("ast", g->d_map, g->tmp, g);
        return (NULL);
    }
    return (g);
}

void bsq(bsq_t *g)
{
    for (g->y = 0; g->d_map[g->y]; g->y++) {
        for (g->x = 0; g->d_map[g->y][g->x] != '\0'; g->x++) {
            g = final_bsq(g);
        }
    }
    g = replace_maps(g);
    my_printf("%a", g->d_map);
}

int main(int ac, char **av)
{
    bsq_t *g = malloc(sizeof(bsq_t));

    if (ac != 2) {
        free(g);
        return (84);
    }
    g = init_struct(g, av[1]);
    if (g == NULL)
        return (84);
    bsq(g);
    my_free("ast", g->d_map, g->tmp, g);
    return (0);
}
