/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** arg_handler
*/

#include "dante.h"

static int description_0(char *name)
{
    my_printf("USAGE:\n\t%s x y\nGOAL:\n\tYour goal is to complete", name);
    my_printf(" the maze the fastest possible.\n");
    return (0);
}

static int description_84(char *name)
{
    my_printf("USAGE:\n\t%s x y\nGOAL:\n\tYour goal is to complete", name);
    my_printf(" the maze the fastest possible.\n");
    return (84);
}

int arg_handler(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h"))
        return (description_0(av[0]));
    if (ac > 1)
        return (description_84(av[0]));
    return (1);
}