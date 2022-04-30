/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** printf
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include "my.h"
    #include <stdint.h>
    #include <stdarg.h>

typedef struct printf_s {
    char percent;
    void (*func) (va_list);
} printf_t;

#endif

void percent_percent(void);
void percent_c(va_list arglist);
void percent_d_i(va_list arglist);
void percent_s(va_list arglist);
void percent_a(va_list arglist);
void percent_f(va_list arglist);
void percent_e(va_list arglist);
void my_printf(char *str, ...);
