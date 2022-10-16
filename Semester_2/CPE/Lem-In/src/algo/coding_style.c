/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** coding_style
*/

#include "lemin.h"

static int tunnel_len(tunnels_t *tunnel)
{
    int len = 0;

    while (tunnel) {
        len++;
        tunnel = tunnel->next;
    }
    return (len);
}

lemin_t *tunnel_loop(lemin_t *g)
{
    g->tunnels = g->ants_tmp->room->tunnel;
    while (g->tunnels) {
        if ((!g->nearest_room && g->tunnels->dest->ants < 1) ||
        (g->nearest_room && g->tunnels->dest->dist < g->nearest_room->dist &&
        g->tunnels->dest->ants < 1 && (g->tunnels->dest->type == END ||
        tunnel_len(g->tunnels->dest->tunnel) > 1)))
            g->nearest_room = g->tunnels->dest;
        g->tunnels = g->tunnels->next;
    }
    return (g);
}

char **nearest_cond(lemin_t *g, char **steps)
{
    if (g->nearest_room) {
        !g->tmp.first ? my_strcat(steps, " ") : 0;
        g->tmp.first = 0;
        g->nearest_room->ants++;
        g->ants_tmp->room->ants--;
        g->ants_tmp->room = g->nearest_room;
        g->nearest_room->type == END ? g->tmp.exited++ : 0;
        my_strcat(steps, g->ants_tmp->name);
        my_strcat(steps, "-");
        my_strcat(steps, g->nearest_room->id);
    }
    return (steps);
}

char **ants_loop(lemin_t *g, char **steps)
{
    while (g->ants_tmp) {
        if (g->ants_tmp->room->type == END || g->ants_tmp->room->ants == 0) {
            g->ants_tmp = g->ants_tmp->next;
            continue;
        }
        g = tunnel_loop(g);
        steps = nearest_cond(g, steps);
        g->ants_tmp = g->ants_tmp->next;
        g->nearest_room = NULL;
    }
    return (steps);
}
