/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** utils
*/

#include "tetris.h"

int nb_line(char *map)
{
    int nb_l = 0;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            nb_l++;
    }
    return (nb_l);
}

int nb_column(char *map)
{
    int nb_c = 0;
    for (; map[nb_c] != '\n'; nb_c++);
    return (nb_c);
}

int nb_line_tetriminos(char **to_count)
{
    int nb_l = 0;

    for (; to_count[nb_l]; nb_l++);
    return (nb_l + 1);
}
