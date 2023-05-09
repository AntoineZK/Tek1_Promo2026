/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** main
*/

#include "general.h"

int main(int ac, char **av)
{
    general_t *g = malloc(sizeof(general_t));

    g = init_struct(g);
    free(g);
    return (0);
}
