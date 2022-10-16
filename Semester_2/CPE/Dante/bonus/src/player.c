/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** player
*/

#include "dante.h"

static void colision_handler(dante_t *g, object_t movement)
{
    if (g->d_map[g->player.y][g->player.x] == 'X') {
        g->player.x -= movement.x;
        g->player.y -= movement.y;
    }
}

void player_handler(dante_t *g)
{
    if (g->input == KEY_RIGHT && g->player.x + 1 < my_strlen(g->d_map[0])) {
        g->player.x++;
        colision_handler(g, g->mv_right);
    }
    if (g->input == KEY_LEFT && g->player.x - 1 >= 0) {
        g->player.x--;
        colision_handler(g, g->mv_left);
    }
    if (g->input == KEY_UP && g->player.y - 1 >= 0) {
        g->player.y--;
        colision_handler(g, g->mv_up);
    }
    if (g->input == KEY_DOWN && g->player.y + 1 < my_strlen(g->d_map[0])) {
        g->player.y++;
        colision_handler(g, g->mv_down);
    }
    if (g->input == KEY_BACKSPACE)
        g->finish = 2;
}
