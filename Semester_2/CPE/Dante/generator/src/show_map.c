/*
** EPITECH PROJECT, 2022
** dante
** File description:
** show_map
*/

#include "../include/generator.h"

void show_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s", map[i]);
        if (map[i + 2] != NULL)
            printf("\n");
    }
}
