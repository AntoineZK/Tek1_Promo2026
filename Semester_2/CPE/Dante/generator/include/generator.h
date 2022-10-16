/*
** EPITECH PROJECT, 2022
** dante
** File description:
** generator
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

int my_strlen(const char *str);
int my_getnbr(char const *str);
int error_gest(int argc, char **argv);
void fill_map(char **map, int x, int y);
void show_map(char **map);
char **alloc_map(char **map, int x, int y);
void create_maze(char **map, int max_x, int max_y);
void make_imperfect(char **map, int x, int y);
