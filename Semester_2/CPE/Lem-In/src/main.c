/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "lemin.h"

int main(void)
{
    lemin_t *g = malloc(sizeof(lemin_t));

    g = my_memset(g, 0, sizeof(lemin_t));
    if (parser(g) != 0)
        return (84);
    if (algo(g) == 84) {
        free_all(g);
        return (84);
    }
    free_all(g);
    return (0);
}
