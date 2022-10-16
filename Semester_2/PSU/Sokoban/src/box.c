/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** box
*/

#include "../include/sokoban.h"

sokoban_t *nb_box(sokoban_t *soko)
{
    int nb_box = 0;
    for (int i = 0; soko->map_buffer[i] != '\0'; i++) {
        if (soko->map_buffer[i] == 'X')
            nb_box++;
    }
    soko->nb_box = nb_box;
    return (soko);
}

sokoban_t *nb_target(sokoban_t *soko)
{
    int nb_target = 0;
    for (int i = 0; soko->map_buffer[i] != '\0'; i++) {
        if (soko->map_buffer[i] == 'O')
            nb_target++;
    }
    soko->nb_target = nb_target;
    return (soko);
}

object_t **box_position(sokoban_t *soko, object_t **boxes, int x, int y)
{
    object_t *box = malloc(sizeof(object_t));
    box == NULL ? exit(my_put_error("Malloc problem\n")) : 0;
    box->x = x;
    box->y = y;
    box->status = 0;
    object_t **new_boxes = malloc(sizeof(object_t *) * (soko->nb_box + 2));
    new_boxes == NULL ? exit(my_put_error("Malloc problem\n")) : 0;
    int i = 0;
    for (; boxes[i]; i++)
        new_boxes[i] = boxes[i];
    new_boxes[i] = box;
    new_boxes[i + 1] = NULL;
    return (new_boxes);
}
