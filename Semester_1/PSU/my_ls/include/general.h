/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** general.h
*/

#pragma once

#include "my.h"
#include "printf.h"
#include "free.h"
#include "lk_list.h"
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

enum flag {
    L,
    A,
    R,
};

typedef struct general_s {
    int *activated_flag;
    lk_list *list;
} general_t;

general_t *init_struct(general_t *g);
int arg_handling(int ac, char **av, general_t *g);
int my_ls(char **av, general_t *g);
void print_color(struct dirent *file);
void perm(mode_t permission);
int use_flag(general_t *g);
