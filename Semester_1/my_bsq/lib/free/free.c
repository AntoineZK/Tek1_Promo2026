/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** free
*/

#include "../../include/free.h"

void free_str(va_list arglist)
{
    free(va_arg(arglist, char *));
}

void free_darray(va_list arglist)
{
    free_double_array(va_arg(arglist, char **));
}

void free_struct(va_list arglist)
{
    free(va_arg(arglist, void *));
}
