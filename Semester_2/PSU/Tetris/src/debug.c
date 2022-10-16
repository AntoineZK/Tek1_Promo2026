/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** debug
*/

#include "tetris.h"
#include "my.h"

int get_color_code(char *line)
{
    if (line == NULL)
        return (84);
    int i = 0;
    int count = 0;

    for (; line[i]; i++) {
        if (line[i] == ' ' && line[i - 1] != ' ')
            count++;
        if (count == 2)
            break;
    }
    line += i + 1;
    return (my_getnbr(line));
}

void get_name(char *str)
{
    my_strcpyto(str, str, my_strlen(str) - 11);
}

void parse_tet(tetris_t *g, char *path, char *name)
{
    char *unparsed_file = open_file(path);
    char **file = parse(unparsed_file, '\n');
    char *first_line = file[0];

    for (int i = 0; file[i]; i++) {
        file[i] = remove_space(file[i]);
    }
    get_name(name);
    file++;
    g->piece = lk_list_add(g->piece, file, name, first_line);
}

int debug(tetris_t *g, char **av, char *path)
{
    DIR *dr = opendir(path);
    struct dirent *file;
    file = readdir(dr);
    char *topath = malloc(sizeof(char) * (4096));
    while (file != NULL) {
        if (check_ext(file->d_name) == 0 &&
        check_file(g, my_strcomb(path, file->d_name), file->d_name) == 0) {
            topath = my_strcomb(path, file->d_name);
            parse_tet(g, topath, file->d_name);
        }
        file = readdir(dr);
    }
    free(topath);
    return (get_param(g, av));
}
