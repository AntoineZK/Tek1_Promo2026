/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** status
*/

#include "../include/sokoban.h"

void is_lose(sokoban_t *soko)
{
    int lose = 0;
    int x;
    int y;

    for (int i = 0; i != soko->nb_box; i++) {
        x = soko->boxes[i]->x;
        y = soko->boxes[i]->y;
        if ((soko->map[y + 1][x] == '#' && soko->map[y][x + 1] == '#') ||
        (soko->map[y - 1][x] == '#' && soko->map[y][x + 1] == '#'))
            lose += 1;
        if ((soko->map[y + 1][x] == '#' && soko->map[y][x - 1] == '#') ||
        (soko->map[y - 1][x] == '#' && soko->map[y][x - 1] == '#'))
            lose += 1;
    }
    lose = lose == soko->nb_box ? 1 : 0;
    soko->blocked = lose;
    soko->exit_code = soko->blocked == 1 ? 1 : 0;
}

int is_win(sokoban_t *soko)
{
    for (int i = 0; soko->boxes[i] != NULL; i++) {
        if (!soko->boxes[i]->status) {
            return (0);
        }
    }
    return (1);
}
