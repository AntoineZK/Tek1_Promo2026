/*
** EPITECH PROJECT, 2022
** new_ls [WSL : Ubuntu-20.04]
** File description:
** ls_l_utils
*/

#include "general.h"

void perm(mode_t permission)
{
    if (S_ISREG(permission))
        my_putchar('-');
    if (S_ISDIR(permission))
        my_putchar('d');
    my_putchar((S_IRUSR & permission ? 'r' : '-'));
    my_putchar((S_IWUSR & permission ? 'w' : '-'));
    my_putchar((S_IXUSR & permission ? 'x' : '-'));
    my_putchar((S_IRGRP & permission ? 'r' : '-'));
    my_putchar((S_IWGRP & permission ? 'w' : '-'));
    my_putchar((S_IXGRP & permission ? 'x' : '-'));
    my_putchar((S_IROTH & permission ? 'r' : '-'));
    my_putchar((S_IWOTH & permission ? 'w' : '-'));
    my_putchar((S_IXOTH & permission ? 'x' : '-'));
    my_putchar(' ');
}
