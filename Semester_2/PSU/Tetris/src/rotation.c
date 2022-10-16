/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** rotation
*/

#include "tetris.h"

int nb_column_tetrimino(char *map)
{
    int nb_c = 0;

    for (; map[nb_c] != '\0'; nb_c++);
    return (nb_c);
}

int column_tetri(int col_tetri, tetris_t *g)
{
    int i_longest = 0;

    for (int i = 0; g->piece->tetrimino[i]; i++) {
        if (my_strlen(g->piece->tetrimino[i]) >=
        my_strlen(g->piece->tetrimino[i_longest]))
            i_longest = i;
    }
    col_tetri = nb_column_tetrimino(g->piece->tetrimino[i_longest]);
    return (col_tetri);
}

char **alloc_darray(int height, int width)
{
    char **tab = malloc(sizeof(char *) * (height + 1));

    for (int y = 0; y < height; y++) {
        tab[y] = malloc(sizeof(char) * (width + 1));
        for (int x = 0; x < width; x++)
            tab[y][x] = ' ';
        tab[y][width] = '\0';
    }
    tab[height] = NULL;
    return (tab);
}

void rotate(tetris_t *g)
{
    char **new_tetri = alloc_darray(column_tetri(0, g),
    nb_line_tetriminos(g->piece->tetrimino));
    int	row = nb_line_tetriminos(g->piece->tetrimino);

    for (int y = 0; row >= 0 && g->piece->tetrimino[y]; y++) {
        row = nb_line_tetriminos(g->piece->tetrimino) - 1 - y;
        for (int x = 0; x < column_tetri(0, g); x++)
            new_tetri[x][row] = g->piece->tetrimino[y][x];
    }

    free_double_array(g->piece->tetrimino);
    g->piece->tetrimino = new_tetri;
}
