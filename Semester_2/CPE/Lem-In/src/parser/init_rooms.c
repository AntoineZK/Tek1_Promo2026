/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** init_rooms
*/

#include "lemin.h"

char *get_room_name(char *str)
{
    char *dest = NULL;
    int size = 0;

    for (; str[size] != ' '; size++);
    dest = malloc(sizeof(char) * (size + 1));
    for (int i = 0; str[i] != ' '; i++)
        dest[i] = str[i];
    dest[size] = '\0';
    return (dest);
}

rooms_t *add_room(lemin_t *g, char *str, type_t type)
{
    rooms_t *tmp = malloc(sizeof(rooms_t));
    tmp->tunnel = NULL;
    tmp->type = type;
    tmp->dist = 0;
    tmp->ants = 0;
    tmp->visited = 0;
    tmp->id = get_room_name(str);
    tmp->x = get_x(str);
    tmp->y = get_y(str);
    tmp->next = g->alg;
    g->alg = tmp;
    return (g->alg);
}

rooms_t *get_start(lemin_t *g)
{
    rooms_t *tmp = g->alg;

    while (tmp) {
        if (tmp->type == START)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

rooms_t *get_end(lemin_t *g)
{
    rooms_t *tmp = g->alg;

    while (tmp) {
        if (tmp->type == END)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

int get_room(lemin_t *g)
{
    int i = 1;
    type_t type = NORMAL;

    g->alg = NULL;
    for (; g->d_map[i]; i++) {
        if (my_strcmp(g->d_map[i], "##start"))
            type = START;
        else if (my_strcmp(g->d_map[i], "##end"))
            type = END;
        if (my_strncmp(g->d_map[i], "##", 2) &&
        check_nbr_arg(g->d_map[i], ' ') != 3)
            return (i);
        if (my_strncmp(g->d_map[i], "##", 2)) {
            g->alg = add_room(g, g->d_map[i], type);
            type = NORMAL;
        }
    }
    return (i);
}
