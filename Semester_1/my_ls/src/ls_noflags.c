/*
** EPITECH PROJECT, 2021
** ls_noflags.c
** File description:
** ls_noflags.c
*/

#include "../include/my.h"
#include "../include/ls.h"

int ls_noflags_arg(ls_t *ls, int argc, char **argv)
{
    if (argc == 2) {
        ls->directory = opendir(argv[1]);
        if (ls->directory == NULL)
            return (84);
        ls_noflags(ls);
        return (0);
    }
    for (int i = 1; i != argc; i++) {
        ls->directory = opendir(argv[i]);
        if (ls->directory == NULL)
            return (84);
        my_putstr(argv[i]);
        my_putstr(":\n");
        ls_noflags(ls);
        i != argc - 1 ? my_putchar('\n') : 0;
    }
    return (0);
}

void ls_noflags(ls_t *ls)
{
    ls->dir = readdir(ls->directory);
    while (ls->dir) {
        if (ls->dir->d_name[0] != '.') {
            my_putstr(ls->dir->d_name);
            my_putchar('\n');
        }
        ls->dir = readdir(ls->directory);
    }
}
