/*
** EPITECH PROJECT, 2022
** solver
** File description:
** check_maze
*/

#include "solver.h"

int check_maze(solver_t *solv)
{
    for (int i = 0; solv->cmaze[i] != '\0'; i++) {
        if (solv->cmaze[i] == 'X' ||
            solv->cmaze[i] == '*' ||
            solv->cmaze[i] == '\n')
            continue;
        else {
            free(solv->cmaze);
            return (1);
        }
    }
    free(solv->cmaze);
    return (0);
}

int maze_error(solver_t *solv, char *filepath)
{
    stat(filepath, &solv->statbuff);
    if ((solv->file_d = open(filepath, O_RDONLY)) == - 1)
        return (1);
    solv->cmaze = malloc(sizeof(char) * solv->statbuff.st_size + 1);
    if (read(solv->file_d, solv->cmaze, solv->statbuff.st_size) <= 0) {
        free(solv);
        return (1);
    }
    close(solv->file_d);
    solv->cmaze[solv->statbuff.st_size] = 0;
    solv->dmaze = my_str_to_word_array(solv->cmaze);
    return (0);
}

int start_end(solver_t *solv)
{
    solv->start.x = 0;
    solv->start.y = 0;
    solv->end.x = solv->nb_column - 1;
    solv->end.y = solv->nb_line - 1;
    return (0);
}

void print_maze(solver_t *solv)
{
    int i = 0;
    for (; solv->dmaze[i + 1] != NULL; i++)
        printf("%s\n", solv->dmaze[i]);
    printf("%s", solv->dmaze[i]);
}

void replace_int_dstar(solver_t *solv, int x, int y)
{
    if (solv->dmaze[y][x] == 'X') {
        solv->int_maze[y][x] = WALL;
    } else if (x == solv->end.x && y == solv->end.y) {
        solv->int_maze[y][x] = END;
    } else {
        solv->int_maze[y][x] = EMPTY;
    }
}
