/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** collision
*/

#include "tetris.h"

static int collision_right(tetris_t *g, int y, int to_break)
{
    for (int x = 0; g->piece->tetrimino[y][x]; x++) {
        g->true_y = g->piece->pos_y - g->y_center + y + 1;
        g->true_x = g->piece->pos_x - g->x_center + x;
        if (g->piece->tetrimino[y][x] == '*' &&
        g->map[g->true_y][g->true_x] == '*') {
            g->piece->pos_x--;
            to_break = 1;
            break;
        }
    }
    return (to_break);
}

static int collision_left(tetris_t *g, int y, int to_break)
{
    for (int x = 0; g->piece->tetrimino[y][x]; x++) {
        g->true_y = g->piece->pos_y - g->y_center + y + 1;
        g->true_x = g->piece->pos_x - g->x_center + x;
        if (g->piece->tetrimino[y][x] == '*' &&
        g->map[g->true_y][g->true_x] == '*') {
            g->piece->pos_x++;
            to_break = 1;
            break;
        }
    }
    return (to_break);
}

static void check_lose(tetris_t *g)
{
    if (g->piece->pos_y - 1 <= g->y_center)
        g->can_continue = false;
}

static int collision_down(tetris_t *g, int y, int to_break)
{
    for (int x = 0; g->piece->tetrimino[y][x]; x++) {
        g->true_y = g->piece->pos_y - g->y_center + y + 1;
        g->true_x = g->piece->pos_x - g->x_center + x;
        if ((g->piece->tetrimino[y][x] == '*' &&
        g->map[g->true_y][g->true_x] == '*') ||
        (g->piece->tetrimino[y][x] == '*' &&
        g->map[g->true_y][g->true_x] == '-')) {
            g->piece->pos_y--;
            check_lose(g);
            place_in_map(g);
            g->piece->status = true;
            to_break = 1;
            break;
        }
    }
    return (to_break);
}

void collision_handler(tetris_t *g, int movement)
{
    int to_break = 0;

    g->true_x = 0;
    g->true_y = 0;
    for (int y = 0; g->piece->tetrimino[y]; y++) {
        if (movement == RIGHT)
            to_break = collision_right(g, y, to_break);
        if (movement == LEFT)
            to_break = collision_left(g, y, to_break);
        if (movement == DROP)
            to_break = collision_down(g, y, to_break);
        if (to_break == 1)
            break;
    }
}
