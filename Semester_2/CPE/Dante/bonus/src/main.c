/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** main
*/

#include "dante.h"

dante_t *init_game(dante_t *g)
{
    create_map();
    g->c_map = stat_file("map.txt");
    g->d_map = my_stwa(g->c_map, '\n');
    g->player.x = 0;
    g->player.y = 0;
    g->mv_up.x = 0;
    g->mv_up.y = -1;
    g->mv_down.x = 0;
    g->mv_down.y = 1;
    g->mv_left.x = -1;
    g->mv_left.y = 0;
    g->mv_right.x = 1;
    g->mv_right.y = 0;
    g->exit.x = 49;
    g->exit.y = 49;
    return (g);
}

void game(dante_t *g)
{
    init_game(g);
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    while (g->finish == 0) {
        erase();
        print_map(g);
        refresh();
        g->input = getch();
        player_handler(g);
        if (g->player.x == g->exit.x && g->player.y == g->exit.y)
            g->finish = 1;
    }
    endwin();
    if (g->finish == 1)
        printf("You win\n");
    else
        printf("You lose\n");
}

int main(int ac, char **av)
{
    dante_t *g = malloc(sizeof(dante_t));
    int arg_value = 0;

    if (g == NULL)
        return (84);
    g = my_memset(g, 0, sizeof(dante_t));
    if (g == NULL)
        return (84);
    arg_value = arg_handler(ac, av);
    if (arg_value == 84)
        return (84);
    if (arg_value == 0)
        return (0);
    game(g);
    system("rm map.txt");
    free_all(g);
    return (0);
}
