/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-dante-thomas.dehennault
** File description:
** utils
*/

#include "solver.h"

int nb_line(solver_t *solv)
{
    int nb_l = 0;
    for (int i = 0; solv->cmaze[i] != '\0'; i++) {
        if (solv->cmaze[i] == '\n')
            nb_l++;
    }
    return (nb_l + 1);
}

int nb_column(solver_t *solv)
{
    int nb_c = 0;
    for (; solv->cmaze[nb_c] != '\n'; nb_c++);
    return (nb_c);
}

void free_all(solver_t *solv)
{
    free_double_array(solv->dmaze);
    free_dint_array(solv->int_maze, solv->nb_line);
    free(solv);
}
