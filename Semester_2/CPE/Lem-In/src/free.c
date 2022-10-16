/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** free
*/

#include "lemin.h"

static void free_struct(lemin_t *g)
{
    rooms_t *room = g->alg;
    rooms_t *tmp_roo = NULL;
    tunnels_t *tmp_tun = NULL;

    while (room) {
        while (room->tunnel) {
            tmp_tun = room->tunnel;
            room->tunnel = room->tunnel->next;
            free(tmp_tun);
        }
        tmp_roo = room;
        room = room->next;
        free(tmp_roo->id);
        free(tmp_roo);
    }
}

static void free_ant(ant_t *ant)
{
    ant_t *tmp = ant;

    while (ant) {
        tmp = ant;
        ant = ant->next;
        free(tmp->name);
        free(tmp);
    }
}

void free_all(lemin_t *g)
{
    free_struct(g);
    free_double_array(g->d_map);
    free_double_array(g->tun);
    free(g->c_map);
    free_ant(g->ants);
    free(g);
}
