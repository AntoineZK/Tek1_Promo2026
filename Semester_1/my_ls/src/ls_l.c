/*
** EPITECH PROJECT, 2021
** ls_l.c
** File description:
** ls_l
*/

#include "../include/my.h"
#include "../include/ls.h"

int ls_l_arg(int argc, char **argv, ls_t *ls)
{
    int size = 0;
    int to_break = 0;

    for (int i = 2; i != argc; i++) {
        size = my_strlen(argv[i]);
        if (size == 2 && argv[i][0] == '.' && argv[i][1] == '/') {
            my_putstr("./:\n");
            ls_l("./", ls);
            i++;
            i != argc ? my_putchar('\n'): to_break++;
        }
        if (to_break != 0)
            return (0);
        my_putstr(argv[i]);
        my_putstr(":\n");
        ls_l(argv[i], ls);
        i != argc - 1 ? my_putchar('\n') : 0;
    }
    return (0);
}

void ls_l(char *str, ls_t *ls)
{
    struct stat statl;

    total(ls, str);
    ls->directory = opendir(str);
    while ((ls->dir = readdir(ls->directory)) != 0) {
        if (ls->dir->d_name[0] != '.') {
            stat(my_strcat(str, ls->dir->d_name), &statl);
            perm(statl.st_mode);
            my_put_nbr(statl.st_nlink);
            name_user(statl.st_uid, statl.st_gid);
            my_put_nbr(statl.st_size);
            my_putchar(' ');
            my_putstr(date(ctime(&statl.st_mtime)));
            my_putchar(' ');
            my_putstr(ls->dir->d_name);
            my_putchar('\n');
        }
    }
}
