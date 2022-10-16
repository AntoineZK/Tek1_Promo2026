/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-dante-thomas.dehennault
** File description:
** solver
*/

#ifndef SOLVER_H_
    #define SOLVER_H_
    #include "my.h"
    #include <stdbool.h>

typedef enum mazetype_s {
    EMPTY,
    WALL,
    END,
    PATH,
} mazetype_t;

typedef enum movement_s {
    RIGHT,
    LEFT,
    UP,
    DOWN,
} movement_t;

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct solver_s {
    char *cmaze;
    struct stat statbuff;
    char **dmaze;
    int **int_maze;
    int file_d;
    int nb_line;
    int nb_column;
    int exit_code;
    position_t start;
    position_t end;
    mazetype_t type;
} solver_t;

#endif

int description_0(void);
int description_84(void);
int check_maze(solver_t *solv);
solver_t *open_maze(solver_t *solv, char *path);
int maze_error(solver_t *solv, char *filepath);
int nb_line(solver_t *solv);
int nb_column(solver_t *solv);
int start_end(solver_t *solv);
solver_t *init_intdstar(solver_t *solv);
void replace_path(solver_t *solv);
int path_finding(int row, int col, solver_t *solv, int op);
void print_maze(solver_t *solv);
solver_t *init_struct(solver_t *solv, char *path);
void free_all(solver_t *solv);
void replace_int_dstar(solver_t *solv, int x, int y);
