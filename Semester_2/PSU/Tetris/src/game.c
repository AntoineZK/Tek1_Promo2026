/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** game
*/

#include "tetris.h"

int able_to_move(int movement, tetris_t *g)
{
    if (movement == RIGHT && (g->piece->pos_x + max_len_line(g)) <
    (my_strlen(g->map[0]) + g->x_center - 1))
        return (1);
    if (movement == LEFT && g->piece->pos_x > g->x_center + 1)
        return (1);
    return (0);
}

void place_in_map(tetris_t *g)
{
    for (int y = 0; g->piece->tetrimino[y]; y++) {
        for (int x = 0; g->piece->tetrimino[y][x]; x++) {
            g->map[g->piece->pos_y - g->y_center + 1 + y]
            [g->piece->pos_x - g->x_center + x] =
            g->piece->tetrimino[y][x] == '*' ?
            '*' : ' ';
            g->color_map[g->piece->pos_y - g->y_center + 1 + y]
            [g->piece->pos_x - g->x_center + x] =
            g->piece->tetrimino[y][x] == '*' ?
            g->piece->color : SPACE;
        }
    }
}

clock_t movement_handler(tetris_t *g, clock_t soft_drop)
{
    float soft_fall = (clock() - soft_drop) / ((float) CLOCKS_PER_SEC);
    int level = g->level >= 5 ? 5 : g->level - 1;
    if (g->input == g->key_right && able_to_move(RIGHT, g)) {
        g->piece->pos_x++;
        collision_handler(g, RIGHT);
    }
    if (g->input == g->key_left && able_to_move(LEFT, g)) {
        g->piece->pos_x--;
        collision_handler(g, LEFT);
    }
    if (g->input == g->key_drop) {
        g->piece->pos_y++;
        collision_handler(g, DROP);
    }
    if (soft_fall > g->speed_fall[level]) {
        g->piece->pos_y++;
        collision_handler(g, DROP);
        soft_drop = clock();
    }
    return (input_handler(g, soft_drop));
}

void print_tetriminos(tetris_t *g)
{
    if (g->piece->status == true && g->piece->next != NULL)
        g->piece = g->piece->next;
    if (g->piece->tetrimino == NULL) {
        g->piece = g->piece->next;
        print_tetriminos(g);
    }
    attron(COLOR_PAIR(g->piece->color));
    for (int y = 0; g->piece->tetrimino[y]; y++) {
        for (int x = 0; g->piece->tetrimino[y][x]; x++) {
            move(g->piece->pos_y + y + 1, g->piece->pos_x + x);
            g->piece->tetrimino[y][x] != ' ' ?
            printw("%c", g->piece->tetrimino[y][x]) : 0;
        }
    }
    attroff(COLOR_PAIR(g->piece->color));
}

void print_map_panel(tetris_t *g)
{
    for (int i = 0; g->panel[i]; i++) {
        move(g->y_center + i, g->term_col / 3 - 10);
        printw("%s\n", g->panel[i]);
    }
    for (int y = 0; g->map[y]; y++) {
        for (int x = 0; g->map[y][x]; x++) {
            move(g->y_center + y, g->x_center + x);
            apply_color(g, x, y);
        }
        printw("\n");
    }
}
