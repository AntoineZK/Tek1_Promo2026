/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** tetriminos
*/

#include "tetris.h"

int get_x(char **line)
{
    int count = 0;
    if (line == NULL)
        return (-2);
    for (int i = 0; line[i]; i++)
        for (int j = 0; line[i][j]; j++)
            count = j > count ? j : count;
    return (count);
}

int get_y(char **line)
{
    int i = 0;
    if (line == NULL)
        return (-2);
    for (; line[i]; i++);
    return (i);
}

static lk_list *add_value(lk_list *list, char **tet, char *id, char *line)
{
    list = malloc(sizeof(lk_list));
    list->tetrimino = tet;
    list->id = id;
    list->x = get_x(tet);
    list->y = get_y(tet);
    list->color = get_color_code(line);
    list->status = false;
    list->next = NULL;
    return (list);
}

lk_list *lk_list_add(lk_list *list, char **tet, char *id, char *line)
{
    lk_list *tmp = list;
    lk_list *new_node = NULL;
    if (list == NULL) {
        list = add_value(list, tet, id, line);
        free(tmp);
        free(new_node);
        return (list);
    }
    while (tmp->next)
        tmp = tmp->next;
    new_node = add_value(new_node, tet, id, line);
    tmp->next = new_node;
    return (list);
}

void show_list(lk_list *list)
{
    lk_list *ltmp = list;
    for (; list != NULL; list = list->next) {
        my_putstr("Tetriminos '");
        my_putstr(list->id);
        if (list->x == -2 || list->y == -2) {
            my_putstr("': error\n");
            continue;
        }
        my_putstr("': size ");
        my_shownbr(list->x);
        my_putstr("*");
        my_shownbr(list->y);
        my_putstr(", color ");
        my_shownbr(list->color);
        for (int i = 0; list->tetrimino[i]; i++) {
            my_putstr("\n");
            my_putstr(list->tetrimino[i]);
        }
        my_putstr("\n");
    }
    list = ltmp;
}
