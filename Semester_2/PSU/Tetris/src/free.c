/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** free
*/

#include "tetris.h"

void free_linked_list(lk_list *list_map)
{
    lk_list *stock;

    while (list_map != NULL) {
        stock = list_map;
        list_map = list_map->next;
        // if (list_map->tetrimino != NULL)
        //     free_double_array(stock->tetrimino);
        // if (list_map->id != NULL)
        //     free(stock->id);
        free(stock);
    }
}

void free_all(tetris_t *g)
{
    free_dint_array(g->color_map, g->nb_l);
    free_linked_list(g->piece);
    free_double_array(g->map);
    free(g->speed_fall);
    free_double_array(g->panel);
    free_double_array(g->next);
    free(g);
}
