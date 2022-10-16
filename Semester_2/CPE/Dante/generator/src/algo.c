/*
** EPITECH PROJECT, 2022
** generator
** File description:
** algo
*/

#include "../include/generator.h"

int check_wall(char **map, int i, int j)
{
    int nbr_star = 0;
    if (i != 0 && map[i - 1] != NULL && map[i - 1][j] == '*')
        nbr_star += 1;
    if (map[i + 1] != NULL && map[i + 1][j] == '*')
        nbr_star += 1;
    if (map[i][j + 1] != 0 && map[i][j + 1] == '*')
        nbr_star += 1;
    if (j != 0 && map[i][j - 1] == '*')
        nbr_star += 1;
    return (nbr_star);
}

int create_impath(char **map, int i, int max_x)
{
    int wall_value = 0;

    for (int j = 0; j < max_x; j++) {
        if (map[i][j] == 'X' && check_wall(map, i, j) == 1) {
            wall_value += 1;
            map[i][j] = '*';
        }
    }
    return (wall_value);
}

void create_maze(char **map, int max_x, int max_y)
{
    int rand_value = rand();
    int x = 0;
    int y = 0;
    int wall_value = 0;
    while (1) {
        map[x][y] = '*';
        rand_value = rand();
        if (x == max_x - 1 && y == max_y - 1)
            break;
        if (rand_value % 2 == 1 && x != max_x - 1)
            x += 1;
        else if (y != max_y - 1)
            y += 1;
    } while (1) {
        for (int i = 0; map[i]; i++)
            wall_value += create_impath(map, i, max_x);
        if (wall_value == 0)
            break;
        wall_value = 0;
    }
}

void make_imperfect(char **map, int x, int y)
{
    for (int i = 0; i < x; i++) {
        map[0][i] = '*';
        map[y - 1][i] = '*';
    }
    for (int i = 0; i < y; i++) {
        map[i][0] = '*';
        map[i][x - 1] = '*';
    }
}
