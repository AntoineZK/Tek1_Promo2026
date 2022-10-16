/*
** EPITECH PROJECT, 2022
** dante
** File description:
** map_alloc
*/

#include "../include/generator.h"

char **alloc_map(char **map, int x, int y)
{
    map[y + 1] = NULL;
    for (int i = 0; i <= y; i++) {
        map[i] = malloc(sizeof(char) * (x + 2));
        map[i][x + 1] = '\0';
    }
    return (map);
}

char **free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
    return (NULL);
}
