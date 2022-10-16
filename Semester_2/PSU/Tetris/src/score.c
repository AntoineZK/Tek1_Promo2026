/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** score
*/

#include "tetris.h"

void score_handler(tetris_t *g)
{
    if (g->del_line % 10 == 0 && g->is_able == 0 && g->del_line > 0) {
        g->is_able++;
        if (g->is_able)
            g->level++;
    }
    g->score = g->del_line * 50;
}
