/*
** EPITECH PROJECT, 2022
** solver
** File description:
** init
*/

#include "solver.h"

solver_t *init_struct(solver_t *solv, char *path)
{
    if (maze_error(solv, path))
        return (NULL);
    solv->nb_column = nb_column(solv);
    solv->nb_line = nb_line(solv);
    if (check_maze(solv) == 1)
        return (NULL);
    start_end(solv);
    solv->exit_code = 0;
    return (solv);
}

solver_t *init_intdstar(solver_t *solv)
{
    solv->int_maze = alloc_dstar_int(solv->nb_line,
    solv->nb_column, solv->int_maze);
    if (solv->int_maze == NULL)
        return (NULL);

    for (int y = 0; y < solv->nb_line; y++) {
        for (int x = 0; x < solv->nb_column; x++) {
            replace_int_dstar(solv, x, y);
        }
    }
    return (solv);
}
