/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** collision
*/

#include "../include/sokoban.h"

void colision_handler(sokoban_t *soko, movement_t movement)
{
    if (soko->map[soko->player.y][soko->player.x] == '#') {
        soko->player.x -= movement.x;
        soko->player.y -= movement.y;
    }
    if (box_colision(soko, movement) == -1) {
        soko->player.x -= movement.x;
        soko->player.y -= movement.y;
    }
    is_lose(soko);
}

int box_asides(sokoban_t *soko, int i)
{
    for (int j = 0; soko->boxes[j]; j++) {
        if (i == j)
            continue;
        if (soko->boxes[j]->x == soko->boxes[i]->x &&
            soko->boxes[j]->y == soko->boxes[i]->y)
            return (1);
    }
    return (0);
}

int box_style(int i_value, movement_t movement, sokoban_t *soko)
{
    if (i_value != -132) {
        if (soko->map[soko->boxes[i_value]->y][soko->boxes[i_value]->x]
        == '#' || box_asides(soko, i_value)) {
            soko->boxes[i_value]->x -= movement.x;
            soko->boxes[i_value]->y -= movement.y;
            return (-1);
        }
    }
    return (0);
}

int box_colision(sokoban_t *soko, movement_t movement)
{
    int i_value = -132;
    for (int i = 0; soko->boxes[i]; i++) {
        if (soko->player.x == soko->boxes[i]->x &&
        soko->player.y == soko->boxes[i]->y) {
            soko->boxes[i]->x += movement.x;
            soko->boxes[i]->y += movement.y;
            soko->boxes[i]->status = (soko->map[soko->boxes[i]->y]
            [soko->boxes[i]->x] == 'O') ? 1 : 0;
            box_asides(soko, i) ? soko->boxes[i]->status = 0 : 0;
            i_value = i;
        }
    }
    return (box_style(i_value, movement, soko));
}
