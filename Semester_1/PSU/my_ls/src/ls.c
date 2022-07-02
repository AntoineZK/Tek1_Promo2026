/*
** EPITECH PROJECT, 2022
** new_ls [WSL : Ubuntu-20.04]
** File description:
** ls
*/

#include "general.h"

void print_color(struct dirent *file)
{
    if (file->d_type == DT_DIR)
        my_printf("\033[1;34m%s\033[0m\n", file->d_name);
    if (file->d_type == DT_REG)
        my_printf("\033[1;32m%s\033[0m\n", file->d_name);
}

int my_ls(char **av, general_t *g)
{
    DIR *dir = opendir("./");
    struct dirent *file = readdir(dir);
    if (dir == NULL)
        return (84);
    for (; file; file = readdir(dir)) {
        if (file->d_name[0] == '.' && g->activated_flag[A] == 0)
            continue;
        print_color(file);
    }
    closedir(dir);
    return (0);
}
