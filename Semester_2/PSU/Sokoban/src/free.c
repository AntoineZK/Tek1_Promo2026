/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** free
*/

#include "../include/sokoban.h"

void free_all(sokoban_t *soko)
{
    free(soko->map_buffer);
    free_double_array(soko->map);
    for (int i = 0; soko->boxes[i]; i++)
        free(soko->boxes[i]);
    free(soko->boxes);
    free(soko);
}
