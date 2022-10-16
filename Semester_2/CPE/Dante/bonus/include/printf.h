/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** printf
*/

#pragma once
#include "my.h"
#include <stdint.h>
#include <stdarg.h>

typedef struct printf_s {
    char percent;
    void (*func) (va_list);
} printf_t;

void percent_c(va_list arglist);
void percent_d_i(va_list arglist);
void percent_s(va_list arglist);
void percent_a(va_list arglist);
void percent(va_list arglist);
void percent_f(va_list arglist);
void percent_e(va_list arglist);
