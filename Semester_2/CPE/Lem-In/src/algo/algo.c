/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** algo
*/

#include "lemin.h"

static void calculate_distance(rooms_t *start)
{
    tunnels_t *tunnels = start->tunnel;

    if (start->type == START) {
        return;
    }
    while (tunnels) {
        if (tunnels->dest->dist == 0 && tunnels->dest->type != END) {
            tunnels->dest->dist = start->dist + 1;
            calculate_distance(tunnels->dest);
        }
        tunnels = tunnels->next;
    }
}

static void init_ants(lemin_t *g)
{
    char *number = NULL;
    ant_t *node = NULL;

    for (int i = g->nb_ants - 1; i >= 0; --i) {
        node = malloc(sizeof(ant_t));
        node->name = malloc(sizeof(char));
        node->name[0] =  '\0';
        node->room = g->start;
        my_strcat(&node->name, "P");
        number = int_to_char(i + 1);
        my_strcat(&node->name, number);
        free(number);
        node->next = g->ants;
        g->ants = node;
    }
}

static int is_possible(rooms_t *start)
{
    tunnels_t *tunnels = start->tunnel;

    while (tunnels) {
        if (tunnels->dest->type == END)
            return (1);
        if (!tunnels->dest->visited)
            start->visited = 1;
        if (!tunnels->dest->visited && is_possible(tunnels->dest))
            return (1);
        tunnels = tunnels->next;
    }
    return (0);
}

void generate_path(lemin_t *g, char **steps)
{
    g->ants_tmp = NULL;
    g->tunnels = NULL;
    g->nearest_room = NULL;
    g->tmp = (tmp_t) {1, 0};

    while (g->tmp.exited != g->nb_ants) {
        g->ants_tmp = g->ants;
        g->tmp.first = 1;
        steps = ants_loop(g, steps);
        g->end->ants = 0;
        my_strcat(steps, "\n");
    }
}

int algo(lemin_t *g)
{
    char *steps = malloc(sizeof(char));

    steps[0] = '\0';
    g->start->ants = g->nb_ants;
    init_ants(g);
    if (!is_possible(g->start)) {
        free(steps);
        return (84);
    }
    calculate_distance(g->end);
    generate_path(g, &steps);
    print_path(g, steps);
    return (0);
}
