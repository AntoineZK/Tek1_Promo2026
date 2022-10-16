/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "tetris.h"

static tetris_t *init_game_two(tetris_t *g)
{
    g->y_center = g->term_line / 2 - 10;
    g->x_center = g->term_col / 2 - 5;
    g->speed_fall = malloc(sizeof(float) * 6);
    g->speed_fall[0] = 0.8;
    g->speed_fall[1] = 0.75;
    g->speed_fall[2] = 0.70;
    g->speed_fall[3] = 0.60;
    g->speed_fall[4] = 0.50;
    g->speed_fall[5] = 0.40;
    return (g);
}

tetris_t *init_game(tetris_t *g)
{
    create_color();
    highscore_get(g);
    g->color_map = alloc_dstar_int(g->nb_l, g->nb_col, g->color_map);
    if (!g->color_map)
        return (NULL);
    for (int y = 0; y < g->nb_l; y++) {
        for (int x = 0; x < g->nb_col; x++)
            replace_int_dstar(g, x, y);
    }
    lk_list *back = g->piece;
    for (;g->piece->next != NULL; g->piece = g->piece->next) {
        g->piece->pos_x = g->term_col / 2;
        g->piece->pos_y = g->term_line / 2 - 10;
    }
    g->piece->pos_x = g->term_col / 2;
    g->piece->pos_y = g->term_line / 2 - 10;
    g->piece = back;
    init_game_two(g);
    return (g);
}

void tetris(tetris_t *g)
{
    lk_list *back = g->piece;
    clock_t soft_drop = clock();
    clock_t first_clock = clock();
    int time = 0;

    while (g->can_continue) {
        time = (clock() - first_clock) / CLOCKS_PER_SEC;
        erase();
        print_map_panel(g);
        print_info(g, time);
        print_tetriminos(g);
        g->hide == false ? print_next(g) : 0;
        g->input = getch();
        soft_drop = movement_handler(g, soft_drop);
        score_handler(g);
        remove_line(g);
        refresh();
        if (g->piece->next == NULL)
            restart(g, "tetriminos");
    }
    g->piece = back;
}

void launch_game(tetris_t *g)
{
    initscr();
    timeout(0);
    getmaxyx(stdscr, g->term_line, g->term_col);
    keypad(stdscr, TRUE);
    curs_set(0);
    init_game(g);
    tetris(g);
    endwin();
}

int main(int argc, char **argv)
{
    tetris_t *g = malloc(sizeof(tetris_t));

    g = my_memset(g, 0, sizeof(tetris_t));
    if (!g)
        return (84);
    init_struct(g);
    if (debug(g, argv, "tetriminos") == 84)
        return (84);
    if (g->help == TRUE && argc == 2)
        return (show_help(argv));
    if (g->debug == TRUE)
        return (show_debug(g));
    full_map(g);
    full_panel(g);
    full_next(g);
    launch_game(g);
    free_all(g);
    return (0);
}
