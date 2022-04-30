/*
** EPITECH PROJECT, 2021
** ls_l_utils
** File description:
** utils
*/

#include "../include/my.h"
#include "../include/ls.h"

void total(ls_t *ls, char *str)
{
    struct stat statl;
    char *temp;
    int i = 0;

    ls->directory = opendir(str);
    while ((ls->dir = readdir(ls->directory))) {
        temp = my_strcat(str, ls->dir->d_name);
        if ((lstat(temp, &statl)) == 0)
            (ls->dir->d_name[0] != '.') ? i += statl.st_blocks : 0;
    }
    closedir(ls->directory);
    free(temp);
    my_putstr("total ");
    my_put_nbr(i / 2);
    my_putchar('\n');
}

char *date(char *time)
{
    char *rslt = malloc(sizeof(char) * 12);
    int j = 0;

    for (int i = 4; i != 16; i++, j++)
        rslt[j] = time[i];
    rslt[j] = '\0';
    return (rslt);
}

void name_user(uid_t user, gid_t grp)
{
    my_putchar(' ');
    my_putstr(getpwuid(user)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(grp)->gr_name);
    my_putchar(' ');
}

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
    my_putchar('.');
    my_putchar(' ');
}
