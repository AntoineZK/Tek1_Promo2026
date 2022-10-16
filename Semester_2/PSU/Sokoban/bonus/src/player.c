/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** player
*/

#include "../include/sokoban.h"

sokoban_t *player_position(sokoban_t *soko)
{
    soko->player.x = -123;
    soko->player.y = -123;
    soko->player.status = -123;
    for (int y = 0; soko->map[y]; y++) {
        for (int x = 0; soko->map[y][x]; x++) {
            soko->player.x = soko->map[y][x] == 'P' ? x : soko->player.x;
            soko->player.y = soko->map[y][x] == 'P' ? y : soko->player.y;
        }
    }
    soko->map[soko->player.y][soko->player.x] = ' ';
    return (soko);
}

void player_handler(sokoban_t *soko)
{
    switch (soko->input) {
        case KEY_RIGHT:
            soko->player.x++;
            colision_handler(soko, soko->mv_right);
            break;
        case KEY_LEFT:
            soko->player.x--;
            colision_handler(soko, soko->mv_left);
            break;
        case KEY_UP:
            soko->player.y--;
            colision_handler(soko, soko->mv_up);
            break;
        case KEY_DOWN:
            soko->player.y++;
            colision_handler(soko, soko->mv_down);
            break;
    }
}

sokoban_t *nb_player(sokoban_t *soko)
{
    int nb_player = 0;
    for (int i = 0; soko->map_buffer[i] != '\0'; i++) {
        if (soko->map_buffer[i] == 'P')
            nb_player++;
    }
    soko->nb_player = nb_player;
    return (soko);
}
