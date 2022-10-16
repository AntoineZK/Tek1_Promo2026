/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** print_path
*/

#include "lemin.h"

static rooms_t *reverse_rooms(rooms_t *rooms)
{
    rooms_t *reverse_rooms = NULL;
    rooms_t *node = NULL;

    while (rooms) {
        node = malloc(sizeof(rooms_t));
        node->id = rooms->id;
        node->tunnel = rooms->tunnel;
        node->type = rooms->type;
        node->dist = rooms->dist;
        node->ants = rooms->ants;
        node->x = rooms->x;
        node->y = rooms->y;
        rooms = rooms->next;
        node->next = reverse_rooms;
        reverse_rooms = node;
    }
    return (reverse_rooms);
}

static void print_path_rooms(lemin_t *g, rooms_t *tmp)
{
    my_putstr("#number_of_ants\n");
    my_putnbr(g->nb_ants);
    my_putstr("\n#rooms\n");
    while (tmp) {
        if (tmp->type == START)
            my_putstr("##start\n");
        if (tmp->type == END)
            my_putstr("##end\n");
        my_putstr(tmp->id);
        my_putstr(" ");
        my_putnbr(tmp->x);
        my_putstr(" ");
        my_putnbr(tmp->y);
        my_putstr("\n");
        tmp = tmp->next;
    }
}

static void free_reversed_rooms(rooms_t *rooms)
{
    rooms_t *tmp = rooms;

    while (tmp) {
        rooms = rooms->next;
        free(tmp);
        tmp = rooms;
    }
}

void print_path(lemin_t *g, char *steps)
{
    rooms_t *tmp = reverse_rooms(g->alg);

    print_path_rooms(g, tmp);
    free_reversed_rooms(tmp);
    my_putstr("#tunnels\n");
    for (int i = 0; g->tun[i]; i++) {
        my_putstr(g->tun[i]);
        my_putchar('\n');
    }
    my_putstr("#moves\n");
    my_putstr(steps);
    free(steps);
}
