/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** tool_defender.C
*/

#include "../include/defender.h"

int is_range(sfVector2f tower, sfVector2f mob, float range)
{
    float distance = 0;
    float value1 = (tower.x - mob.x) * (tower.x - mob.x);
    float value2 = (tower.y - mob.y) * (tower.y - mob.y);
    distance = sqrtf(value1 + value2);
    if (distance <= (range * 10))
        return (1);
    return (0);
}

void update_cd(defender_t *g, float time)
{
    tower_t *backup = g->ts;
    for (;g->ts != NULL; g->ts = g->ts->next)
        if (g->ts->cd > 0)
            g->ts->cd -= time;
    g->ts = backup;
}

void time_action(defender_t *g)
{
    update_cd(g, g->time.microseconds);
    sfClock_restart(g->clock);
}

void display_life(defender_t *def, char *line, sfVector2f pos, sfVector2f siz)
{
    text_t *text = malloc(sizeof(text_t));
    sfVector2f loc;
    loc.x = pos.x - siz.x;
    loc.y = pos.y;
    text->color = sfBlack;
    text->txt = sfText_create();
    text->font = sfFont_createFromFile("res/font.ttf");
    sfText_setString(text->txt, line);
    sfText_setFont(text->txt, text->font);
    sfText_setPosition(text->txt, loc);
    sfText_setCharacterSize(text->txt, 20);
    sfText_setColor(text->txt, text->color);
    sfRenderWindow_drawText(def->wdw, text->txt, NULL);
    sfText_destroy(text->txt);
    sfFont_destroy(text->font);
    free(text);
    free(line);
}
