/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** color
*/

#include "tetris.h"

void create_color(void)
{
    use_default_colors();
    start_color();
    init_pair(1, COLOR_YELLOW,  -1);
    init_pair(2, COLOR_CYAN, -1);
    init_pair(3, COLOR_GREEN,  -1);
    init_pair(4, COLOR_RED, -1);
    init_pair(5, COLOR_MAGENTA,  -1);
    init_pair(6, COLOR_BLUE,  -1);
    init_pair(7, COLOR_WHITE,  -1);
}

void replace_int_dstar(tetris_t *g, int x, int y)
{
    if (g->map[y][x] == '+' || g->map[y][x] == '-' || g->map[y][x] == '|') {
        g->color_map[y][x] = WALL;
    } else {
        g->color_map[y][x] = SPACE;
    }
}

void apply_color(tetris_t *g, int x, int y)
{
    if (g->color_map[y][x] != 1 && g->color_map[y][x] != 0) {
        attron(COLOR_PAIR(g->color_map[y][x]));
        printw("%c", g->map[y][x]);
        attroff(COLOR_PAIR(g->color_map[y][x]));
    } else {
        printw("%c", g->map[y][x]);
    }
}
