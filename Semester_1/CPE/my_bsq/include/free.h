/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** free
*/

#pragma once

#include "my.h"
#include <stdint.h>
#include <stdarg.h>

typedef struct free_s {
    char to_free;
    void (*func) (va_list);
} free_t;

void free_str(va_list arglist);
void free_darray(va_list arglist);
void free_struct(va_list arglist);
void my_free(char *str, ...);
