/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** shoot.c
*/

#include "../include/defender.h"

void initialised_checpoint(defender_t *g)
{
    g->cp[0].direc = 'B';
    g->cp[0].limit = 702;
    g->cp[1].direc = 'D';
    g->cp[1].limit = 486;
    g->cp[2].direc = 'H';
    g->cp[2].limit = 486;
    g->cp[3].direc = 'D';
    g->cp[3].limit = 810;
    g->cp[4].direc = 'B';
    g->cp[4].limit = 918;
    g->cp[5].direc = 'D';
    g->cp[5].limit = 1134;
    g->cp[6].direc = 'H';
    g->cp[6].limit = -200;
}

void mob_mouve(defender_t *g)
{
    if (g->cp[g->mobs->checkp].direc == 'B') {
        g->mobs->pos.y += g->mobs->speed * (g->time.microseconds / 1000000.0);
        if (g->cp[g->mobs->checkp].limit < g->mobs->pos.y)
            g->mobs->checkp++;
    }
    if (g->cp[g->mobs->checkp].direc == 'D') {
        g->mobs->pos.x += g->mobs->speed * (g->time.microseconds / 1000000.0);
        if (g->cp[g->mobs->checkp].limit < g->mobs->pos.x)
            g->mobs->checkp++;
    }
    if (g->cp[g->mobs->checkp].direc == 'H') {
        g->mobs->pos.y -= g->mobs->speed * (g->time.microseconds / 1000000.0);
        if (g->cp[g->mobs->checkp].limit > g->mobs->pos.y)
            g->mobs->checkp++;
    }
    if (g->cp[g->mobs->checkp].direc == 'G') {
        g->mobs->pos.x -= g->mobs->speed * (g->time.microseconds / 1000000.0);
        if (g->cp[g->mobs->checkp].limit > g->mobs->pos.x)
            g->mobs->checkp++;
    }
}

void mob_end(defender_t *g)
{
    if (g->mobs->pos.y <= -80 && g->mobs->checkp == 6) {
        g->life--;
        g->mobs->pos = find_char(g, 'S');
        g->mobs->checkp = 0;
    }
}

void wave_launch(defender_t *g)
{
    if (g->wave_list[g->wave] == NULL && g->mobs == NULL) {
        g->end = 1;
        return;
    }
    if (g->mobs == NULL) {
        if (g->mob_text != NULL)
            sfTexture_destroy(g->mob_text);
        g->mobs = wave_creator(g, find_char(g, 'S'));
        g->wave++;
    }
}

void mob_loop(defender_t *g)
{
    sfVector2f pos;
    wave_launch(g);
    mob_t *backup = g->mobs;
    for (;g->mobs != NULL; g->mobs = g->mobs->next) {
        mob_mouve(g);
        mob_end(g);
        pos.x = g->mobs->pos.x - g->mobs->size.x;
        pos.y = g->mobs->pos.y - g->mobs->size.y;
        animation_goblin(g);
        sfSprite_setPosition(g->mobs->sprite, pos);
        display_life(g, int_to_char(g->mobs->life), pos, g->mobs->size);
        sfRenderWindow_drawSprite(g->wdw, g->mobs->sprite, NULL);
    }
    g->mobs = backup;
}
