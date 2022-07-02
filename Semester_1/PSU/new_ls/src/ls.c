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
        my_printf("\033[1;34m %s\n", file->d_name);
    if (file->d_type == DT_REG)
        my_printf("\033[1;32m %s\n", file->d_name);
}

int my_ls(char **av)
{
    DIR *dir = opendir("./");
    struct dirent *file = readdir(dir);
    if (dir == NULL)
        return (84);
    while (file) {
        if (file->d_name[0] != '.')
            print_color(file);
        file = readdir(dir);
    }
    closedir(dir);
    return (0);
}
