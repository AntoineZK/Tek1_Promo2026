/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** tower_loop
*/

#include "../include/defender.h"

void set_point_laser(defender_t *g, sfVertexArray *laser, sfColor color)
{
    sfVertex point1;
    sfVertex point2;
    sfVertex point3;
    sfVertex point4;
    sfVector2f pos1 = {g->mobs->pos.x - 10, g->mobs->pos.y + 10};
    sfVector2f pos2 = {g->mobs->pos.x + 10, g->mobs->pos.y - 10};
    sfVector2f pos3 = {g->ts->pos.x - 10, g->ts->pos.y - 10};
    sfVector2f pos4 = {g->ts->pos.x + 10, g->ts->pos.y + 10};
    point1.position = pos1;
    point1.color = color;
    point2.position = pos2;
    point2.color = color;
    point3.color = color;
    point3.position = pos3;
    point4.color = color;
    point4.position = pos4;
    sfVertexArray_append(laser, point1);
    sfVertexArray_append(laser, point2);
    sfVertexArray_append(laser, point3);
    sfVertexArray_append(laser, point4);
}

void draw_shoot(defender_t *g, sfColor color)
{
    sfVertexArray *laser = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(laser, sfQuads);
    set_point_laser(g, laser, color);
    sfRenderWindow_drawVertexArray(g->wdw, laser, 0);
    sfVertexArray_destroy(laser);
}
