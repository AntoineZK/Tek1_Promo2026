/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** init
*/

#include "../include/sokoban.h"

sokoban_t *init_movement(sokoban_t *soko)
{
    soko->mv_up.x = 0;
    soko->mv_up.y = -1;
    soko->mv_down.x = 0;
    soko->mv_down.y = 1;
    soko->mv_left.x = -1;
    soko->mv_left.y = 0;
    soko->mv_right.x = 1;
    soko->mv_right.y = 0;
    return (soko);
}

sokoban_t *init_struct(sokoban_t *soko, char *map)
{
    if (map_error(soko, map))
        return (NULL);
    if (check_map(soko))
        return (NULL);
    soko = nb_box(soko);
    soko = nb_player(soko);
    soko = nb_target(soko);
    if (soko->nb_player != 1)
        return (NULL);
    soko = player_position(soko);
    soko->boxes = init_boxes(soko);
    soko->blocked = 0;
    soko->reset = 0;
    soko = init_movement(soko);
    return (soko);
}

object_t **init_boxes(sokoban_t *soko)
{
    object_t **boxes = malloc(sizeof(object_t *));
    boxes == NULL ? exit(my_put_error("Malloc problem\n")) : 0;
    boxes[0] = NULL;
    for (int y = 0; soko->map[y]; y++) {
        for (int x = 0; soko->map[y][x] != '\0'; x++) {
            boxes = soko->map[y][x] == 'X' ?
            box_position(soko, boxes, x, y) : boxes;
            soko->map[y][x] == 'X' ? soko->map[y][x] = ' ' : 0;
        }
    }
    return (boxes);
}
