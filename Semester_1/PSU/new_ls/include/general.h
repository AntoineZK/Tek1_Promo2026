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

typedef struct general_s {
} general_t;

general_t *init_struct(general_t *g);
int my_ls(char **av);
