/*
** EPITECH PROJECT, 2022
** my_bsq
** File description:
** map
*/

#include "bsq.h"

int true_nbline(bsq_t *bsq)
{
    int true_nb = 0;

    for (int i = 0; bsq->c_map[i] != '\0'; i++) {
        if (bsq->c_map[i] == '\n')
            true_nb++;
    }
    if (true_nb != bsq->nb_line)
        return (0);
    return (true_nb);
}

bsq_t *replace_maps(bsq_t *bsq)
{
    for (int y = bsq->max_y; y < bsq->max_y + bsq->max_square; y++) {
        for (int x = bsq->max_x; x < bsq->max_x + bsq->max_square; x++) {
            bsq->d_map[y][x] = 'x';
        }
    }
    return (bsq);
}
