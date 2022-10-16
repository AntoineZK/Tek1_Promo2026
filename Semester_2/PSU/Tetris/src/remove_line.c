/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** remove_line
*/

#include "tetris.h"

static void remove_cond_two(tetris_t *g, int y, int i)
{
    for (int j = y; j - 1 > 0; j--)
        g->map[j][i] = g->map[j - 1][i];
}

static int remove_cond(tetris_t *g, int counter, int y)
{
    if (counter == my_strlen(g->map[y]) - 2) {
        for (int i = 1; g->map[y][i + 1]; i++)
            remove_cond_two(g, y, i);
        g->is_able = 0;
        g->del_line++;
        counter = 0;
    }
    return (counter);
}

void remove_line(tetris_t *g)
{
    int counter = 0;
    for (int y = 0; g->map[y]; y++) {
        for (int x = 0; g->map[y][x]; x++) {
            g->map[y][x] == '*' ? counter++ : 0;
            counter = remove_cond(g, counter, y);
        }
        counter = 0;
    }
}
