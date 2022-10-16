/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** free_linked_list.c
*/

#include "../include/defender.h"

void free_element_map(map_t *list_map)
{
    map_t *stock;
    while (list_map != NULL) {
        stock = list_map;
        list_map = list_map->next;
        sfSprite_destroy(stock->value->sprite);
        sfTexture_destroy(stock->value->texture);
        free(stock->value);
        free(stock);
    }
}

void free_tower(tower_t *ts)
{
    tower_t *stock;
    while (ts != NULL) {
        stock = ts;
        ts = ts->next;
        sfClock_destroy(stock->clock_tower);
        sfSprite_destroy(stock->sprite);
        sfTexture_destroy(stock->texture);
        free(stock);
    }
}

void free_mobs(mob_t *ts)
{
    mob_t *stock;
    while (ts != NULL) {
        stock = ts;
        ts = ts->next;
        sfClock_destroy(stock->clock_monster);
        sfSprite_destroy(stock->sprite);
        free(stock);
    }
}
