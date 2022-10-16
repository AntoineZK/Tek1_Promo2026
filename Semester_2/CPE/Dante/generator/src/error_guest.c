/*
** EPITECH PROJECT, 2022
** dante
** File description:
** error_guest
*/

#include "../include/generator.h"

int error_gest(int argc, char **argv)
{
    if (argc <= 2 || argc >= 5)
        return (84);
    for (int i = 0; argv[1][i]; i++)
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return (84);
    for (int i = 0; argv[2][i]; i++)
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return (84);
    return (0);
}
