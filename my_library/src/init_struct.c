/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** init_struct
*/

#include "general.h"

general_t *init_struct(general_t *g)
{
    g = my_memset(g, 0, sizeof(general_t));
    return (g);
}
