/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** description
*/

#include "tetris.h"

void my_strcpyto(char *str, char *cpy, int len)
{
    int i = 0;
    for (; str[i] && i <= len; i++) {
        cpy[i] = str[i];
    }
    cpy[i] = '\0';
}

int get_param(tetris_t *g, char **av)
{
    for (int i = 0; av[i]; i++) {
        if (add_param(g, av, i) == 84)
            return (84);
    }
    return (0);
}

int check_ext(char *str)
{
    char tet[11] = ".tetrimino";
    int i = my_strlen(str);
    for (; str[i] != '.'; i--);
    for (int j = 0; str[i]; i++, j++)
        if (str[i] != tet[j]) {
            printf("ici\n");
            return (84);
        }
    if (i <= 10)
        return (84);
    return (0);
}

int check_line(char *line)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] != '*' || line[i] != ' ')
            return (84);
    }
    return (0);
}

int check_file(tetris_t *g, char *topath, char *name)
{
    char *file = open_file(topath);
    int i = 0;
    for (; file[i] != '\n'; i++) {
        if ((file[i] < '0' || file[i] > '9') && file[i] != ' ') {
            g->piece = lk_list_add(g->piece, NULL, name, NULL);
            return (84);
        }
    }
    return (0);
}
