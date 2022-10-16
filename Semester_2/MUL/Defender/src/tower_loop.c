/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** tower_loop
*/

#include "../include/defender.h"

int shoot_action(defender_t *g)
{
    if (g->ts->effect == 1 || g->ts->effect == 4) {
        draw_shoot(g, sfYellow);
        g->mobs->life -= g->ts->damage;
    }
    if (g->ts->effect == 2) {
        draw_shoot(g, sfBlue);
        g->mobs->speed = g->mobs->speed_max -
        (g->ts->damage * g->mobs->speed_max / 100);
        g->mobs->life -= 5;
    }
    if (g->ts->effect == 0 || g->ts->effect == 5) {
        draw_shoot(g, sfRed);
        int damage = g->ts->damage - g->mobs->armor;
        if (damage <= 0)
            damage = 1;
        g->mobs->life -= damage;
    }
    if (g->mobs->life <= 0)
        return (1);
    return (0);
}

void remove_mob(defender_t *g)
{
    mob_t *backup = g->mobs;
    g->money += 50;
    if (g->mobs->life <= 0) {
        g->mobs = g->mobs->next;
        sfSprite_destroy(backup->sprite);
        free(backup);
        return;
    }
    mob_t *save = g->mobs;
    for (int i = 0; i == 0 && g->mobs->next != NULL; g->mobs = g->mobs->next) {
        if (g->mobs->next->life <= 0) {
            save = g->mobs->next;
            g->mobs->next = g->mobs->next->next;
            sfSprite_destroy(save->sprite);
            free(save);
            i++;
        }
    }
    g->mobs = backup;
}

void tower_shoot(defender_t *g)
{
    if (g->ts->effect == 3) {
        g->money += g->ts->damage;
        g->ts->cd = g->ts->atksp;
        return;
    }
    int i = 1;
    if (g->ts->effect == 5)
        i = 3;
    mob_t *backup = g->mobs;
    int death = 0;
    for (; i != 0 && g->mobs != NULL; g->mobs = g->mobs->next) {
        if (is_range(g->ts->pos, g->mobs->pos, g->ts->range)) {
            death += shoot_action(g);
            g->ts->cd = g->ts->atksp;
            i--;
        }
    }
    g->mobs = backup;
    for (int j = 0; j != death; j++)
        remove_mob(g);
}

void tower_loop(defender_t *g)
{
    sfVector2f pos;
    tower_t *backup = g->ts;
    for (;g->ts != NULL; g->ts = g->ts->next) {
        if (g->ts->cd <= 0)
            tower_shoot(g);
        pos.x = g->ts->pos.x - g->ts->size.x;
        pos.y = g->ts->pos.y - g->ts->size.y;
        if (g->ts->effect == 5) {
            anim_tower_one(g, pos);
        } else if (g->ts->effect == 4) {
            anim_tower_two(g, pos);
        } else {
            sfSprite_setPosition(g->ts->sprite, pos);
            sfRenderWindow_drawSprite(g->wdw, g->ts->sprite, NULL);
        }
    }
    g->ts = backup;
}
