/*
** EPITECH PROJECT, 2021
** ls_main
** File description:
** ls_main
*/

#include "../include/my.h"
#include "../include/ls.h"

int main(int argc, char **argv)
{
    ls_t *ls = malloc(sizeof(ls_t));

    if (argc == 1) {
        ls->directory = opendir("./");
        if (ls->directory == NULL)
            return (84);
        ls_noflags(ls);
        closedir(ls->directory);
    } else if (argv[1][0] == '-') {
        flags(argc, argv, ls);
    } else {
        if (ls_noflags_arg(ls, argc, argv) == 84)
            return (84);
        closedir(ls->directory);
    }
    free(ls);
    return (0);
}
