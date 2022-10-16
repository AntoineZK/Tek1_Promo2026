/*
** EPITECH PROJECT, 2022
** solver
** File description:
** algo
*/

#include "solver.h"

void replace_path(solver_t *solv)
{
    for (int y = 0; y < solv->nb_line; y++) {
        for (int x = 0; x < solv->nb_column; x++) {
            solv->int_maze[y][x] == PATH ? solv->dmaze[y][x] = 'o' : 0;
            solv->int_maze[y][x] == END ? solv->dmaze[y][x] = 'o' : 0;
        }
    }
}

static int algo_cond(int row, int col, solver_t *solv, int op)
{
    if (row - 1 >= 0 && op != DOWN && path_finding(row - 1, col, solv, UP)) {
        solv->int_maze[row][col] = PATH;
        return (1);
    }
    if (col + 1 < solv->nb_column && op != LEFT &&
    path_finding(row, col + 1, solv, RIGHT)) {
        solv->int_maze[row][col] = PATH;
        return (1);
    }
    if (row + 1 < solv->nb_line && op != UP &&
    path_finding(row + 1, col, solv, DOWN)) {
        solv->int_maze[row][col] = PATH;
        return (1);
    }
    if (col - 1 >= 0 && op != RIGHT &&
    path_finding(row, col - 1, solv, LEFT)) {
        solv->int_maze[row][col] = PATH;
        return (1);
    }
    return (0);
}

int path_finding(int row, int col, solver_t *solv, int op)
{
    if (solv->int_maze[row][col] == END)
        return (1);
    if (solv->int_maze[row][col] == EMPTY) {
        solv->int_maze[row][col] = WALL;
        if (algo_cond(row, col, solv, op))
            return (1);
    }
    return (0);
}
