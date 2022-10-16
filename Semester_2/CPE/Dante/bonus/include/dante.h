/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** dante
*/

#pragma once
#include "my.h"
#include "printf.h"
#include <ncurses.h>

typedef struct object_s {
    int x;
    int y;
} object_t;

typedef struct dante_s {
    char **d_map;
    char *c_map;
    int input;
    int finish;
    object_t player;
    object_t exit;
    object_t mv_right;
    object_t mv_left;
    object_t mv_up;
    object_t mv_down;
} dante_t;

int arg_handler(int ac, char **av);
void create_map(void);
void print_map(dante_t *g);
void free_all(dante_t *g);
void player_handler(dante_t *g);
