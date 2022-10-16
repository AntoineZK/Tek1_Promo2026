/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "solver.h"

int solver(char *path)
{
    int exit_code = 0;
    solver_t *solv = malloc(sizeof(solver_t));
    if (solv == NULL)
        return (my_put_error("Malloc Problem\n"));
    if (init_struct(solv, path) == NULL)
        return (my_put_error("Map Problem\n"));
    if (init_intdstar(solv) == NULL)
        return (my_put_error("Map Problem\n"));
    if (!path_finding(solv->start.y, solv->start.x, solv, 0)) {
        free_all(solv);
        return (my_putstr("no solution found"));
    } else {
        replace_path(solv);
        print_maze(solv);
    }
    free_all(solv);
    return (exit_code);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return (description_84());
    } else if (argc == 2 && my_strcmp(argv[1], "-h")) {
        return (description_0());
    } else {
        return (solver(argv[1]));
    }
}
