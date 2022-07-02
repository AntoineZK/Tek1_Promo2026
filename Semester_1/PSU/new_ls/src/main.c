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
    if (ac == 1) {
        free(g);
        return (my_ls(av));

    }
    return (0);
}
