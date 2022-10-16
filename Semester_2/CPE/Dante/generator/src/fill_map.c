/*
** EPITECH PROJECT, 2022
** dante
** File description:
** fill_map
*/

#include "../include/generator.h"

void fill_map(char **map, int x, int y)
{
    int i = 0;
    int j = 0;
    for (; i < y; i++) {
        for (; j < x; j++) {
            map[i][j] = 'X';
        }
        j = 0;
    }
    __pid_t pid = getpid();
    srand(pid);
    create_maze(map, x, y);
}
