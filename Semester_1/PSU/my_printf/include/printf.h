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

typedef struct printf_two_s {
    char percent;
    void (*func) (va_list, char *str, int i);
} printf_two_t;

#endif

void percent_percent(void);
void percent_c(va_list arglist);
void percent_d_i(va_list arglist);
void percent_s(va_list arglist);
void percent_l(va_list arglist, char *str, int i);
void percent_h(va_list arglist, char *str, int i);
void hashtag(va_list arglist, char *str, int i);
void percent_a(va_list arglist);
void percent_f(va_list arglist);
void percent_e(va_list arglist);
void percent_u(va_list arglist);
void percent_b(va_list arglist);
void percent_o(va_list arglist);
void percent_x_min(va_list arglist);
void percent_x_maj(va_list arglist);
void percent_p(va_list arglist);
void my_printf(char *str, ...);
