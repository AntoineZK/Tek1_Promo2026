/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_codingstyle
*/

#include "../include/my.h"
#include "../include/navy.h"

void codingstyle1(char **p1_map, char **p2_map)
{
    my_putstr("\nmy positions:\n");
    show_map(p1_map);
    my_putstr("\nenemy's positions:\n");
    show_map(p2_map);
}

int codingstyle2(char **map, int i)
{
    for (int j = 0; j < 8; j++) {
        if (map[i][j] >= '1' && map[i][j] <= '8')
            return (0);
    }
    return (1);
}

void codingstyle3(int i, char **map)
{
    my_put_nbr(i - 1);
    my_putchar('|');
    for (int j = 0; j < 8; j++) {
        j != 0 ? my_putchar(' ') : 0;
        my_putchar(map[i - 2][j]);
    }
    my_putchar('\n');
}
