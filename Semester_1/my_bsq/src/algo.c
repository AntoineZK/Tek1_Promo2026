/*
** EPITECH PROJECT, 2022
** my_bsq
** File description:
** algo
*/

#include "bsq.h"

static bsq_t *research_bsq_three(bsq_t *bsq, int j)
{
    for (int i = bsq->x; i < bsq->x + bsq->square_size; i++) {
        if (bsq->d_map[j][i] == 'o') {
            bsq->obstacle = 1;
            break;
        }
    }
    return (bsq);
}

static bsq_t *research_bsq_two(bsq_t *bsq)
{
    bsq->obstacle = 0;
    for (int j = bsq->y; j < bsq->y + bsq->square_size; j++) {
        bsq = research_bsq_three(bsq, j);
        if (bsq->obstacle)
            break;
    }
    return (bsq);
}

static bsq_t *get_coord_bsq(bsq_t *bsq)
{
    if (bsq->max_square < bsq->square_size) {
        bsq->max_square = bsq->square_size;
        bsq->max_x = bsq->x;
        bsq->max_y = bsq->y;
    }
    bsq->width = 1;
    bsq->height = 1;
    return (bsq);
}

static bsq_t *research_bsq(bsq_t *bsq)
{
    for (; bsq->x + bsq->width < bsq->max_width &&
    bsq->d_map[bsq->y][bsq->x + bsq->width] != 'o'; bsq->width++);
    for (; bsq->y + bsq->height < bsq->nb_line &&
    bsq->d_map[bsq->y + bsq->height][bsq->x] != 'o'; bsq->height++);
    bsq->square_size = bsq->height > bsq->width ? bsq->width : bsq->height;
    while (bsq->square_size > 1) {
        bsq = research_bsq_two(bsq);
        if (!bsq->obstacle)
            break;
        else
            bsq->square_size--;
    }
    bsq = get_coord_bsq(bsq);
    return (bsq);
}

bsq_t *final_bsq(bsq_t *bsq)
{
    if (bsq->d_map[bsq->y][bsq->x] == '.') {
        bsq = research_bsq(bsq);
    }
    return (bsq);
}
