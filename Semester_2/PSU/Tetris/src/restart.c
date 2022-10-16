/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** restart
*/

#include "tetris.h"

static lk_list *add_value(lk_list *list, char **tet, tetris_t *g)
{
    list = malloc(sizeof(lk_list));
    list->tetrimino = tet;
    list->id = "tetrimino";
    list->x = get_x(tet);
    list->y = get_y(tet);
    list->color = 3;
    list->pos_x = g->term_col / 2;
    list->pos_y = g->term_line / 2 - 10;
    list->status = false;
    list->next = NULL;
    return (list);
}

lk_list *lk_list_add_bis(lk_list *list, char **tet, tetris_t *g)
{
    lk_list *tmp = list;
    lk_list *new_node = NULL;
    if (list == NULL) {
        list = add_value(list, tet, g);
        free(tmp);
        free(new_node);
        return (list);
    }
    while (tmp->next)
        tmp = tmp->next;
    new_node = add_value(new_node, tet, g);
    tmp->next = new_node;
    return (list);
}

void parse_tet_2(tetris_t *g, char *path)
{
    char *unparsed_file = open_file(path);
    char **file = parse(unparsed_file, '\n');

    for (int i = 0; file[i]; i++) {
        file[i] = remove_space(file[i]);
    }
    file++;
    g->piece = lk_list_add_bis(g->piece, file, g);
}

void restart(tetris_t *g, char *path)
{
    DIR *dr = opendir(path);
    struct dirent *file;
    file = readdir(dr);
    char *topath = malloc(sizeof(char) * (4096));
    while (file != NULL) {
        if (check_ext(file->d_name) == 0 &&
        check_file(g, my_strcomb(path, file->d_name), file->d_name) == 0) {
            topath = my_strcomb(path, file->d_name);
            parse_tet_2(g, topath);
        }
        file = readdir(dr);
    }
}
