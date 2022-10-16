/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** tower_function
*/

#include "../include/defender.h"

tower_t *nod_tower(char **wave_data, sfVector2f pos, sfIntRect *rect)
{
    tower_t *nod = malloc(sizeof(tower_t));
    nod->texture = sfTexture_createFromFile(wave_data[0], NULL);
    nod->sprite = sfSprite_create();
    sfSprite_setTexture(nod->sprite, nod->texture, sfTrue);
    if (rect != NULL)
        sfSprite_setTextureRect(nod->sprite, *rect);
    nod->damage = my_getnbr(wave_data[1]);
    nod->atksp = my_getnbr(wave_data[2]) * 1000000;
    nod->cd = 0;
    nod->range = my_getnbr(wave_data[3]);
    nod->effect = my_getnbr(wave_data[4]);
    nod->size.x = my_getnbr(wave_data[5]) / 2;
    nod->size.y = my_getnbr(wave_data[6]) / 2;
    nod->tow_id = my_getnbr(wave_data[7]);
    nod->clock_tower = sfClock_create();
    nod->pos = pos;
    return (nod);
}

void tower_add(defender_t *g, char **wave_data, sfVector2f pos, sfIntRect *rec)
{
    tower_t *nod = nod_tower(wave_data, pos, rec);
    nod->next = NULL;
    if (g->ts == NULL)
        g->ts = nod;
    else {
        tower_t *backup = g->ts;
        for (; g->ts->next != NULL; g->ts = g->ts->next);
        g->ts->next = nod;
        g->ts = backup;
    }
    free_double_array(wave_data);
}

void tower_update(defender_t *g, char **wave_data, sfIntRect *rect)
{
    g->ts->damage = my_getnbr(wave_data[1]);
    g->ts->atksp = my_getnbr(wave_data[2]) * 1000000;
    g->ts->cd = my_getnbr(wave_data[2]) * 1000000;
    g->ts->range = my_getnbr(wave_data[3]);
    g->ts->effect = my_getnbr(wave_data[4]);
    g->ts->size.x = my_getnbr(wave_data[5]) / 2;
    g->ts->size.y = my_getnbr(wave_data[6]) / 2;
    g->ts->tow_id = my_getnbr(wave_data[7]);
    sfTexture_destroy(g->ts->texture);
    sfSprite_destroy(g->ts->sprite);
    g->ts->texture = sfTexture_createFromFile(wave_data[0], NULL);
    g->ts->sprite = sfSprite_create();
    sfSprite_setTexture(g->ts->sprite, g->ts->texture, sfTrue);
    if (rect != NULL)
        sfSprite_setTextureRect(g->ts->sprite, *rect);
    free_double_array(wave_data);
}
