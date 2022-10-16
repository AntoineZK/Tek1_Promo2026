/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** options
*/

#include "rpg.h"
#include "utils/options.h"

options_t *options_create(void)
{
    options_t *options = malloc(sizeof(options_t));
    options->keys = malloc(sizeof(int) * 12);
    options->music_volume = 50.0;
    options->sound_volume = 50.0;
    options->fullscreen = 0;
    options->resolution_index = 2;
    options->resolution[0] = 1920;
    options->resolution[1] = 1080;
    options->keys[UP_KEY] = sfKeyZ;
    options->keys[DOWN_KEY] = sfKeyS;
    options->keys[LEFT_KEY] = sfKeyQ;
    options->keys[RIGHT_KEY] = sfKeyD;
    options->keys[HIT_KEY] = sfKeySpace;
    options->keys[ARROW_KEY] = sfKeyLShift;
    options->keys[DASH_KEY] = sfKeySpace;
    options->keys[INTERACT_KEY] = sfKeyE;
    options->keys[PAUSE_KEY] = sfKeyEscape;
    options->keys[INVENTORY_KEY] = sfKeyI;
    options->keys[MINIMAP_KEY] = sfKeyM;
    options->keys[11] = -1;
    return (options);
}

void options_destroy(options_t *options)
{
    free(options->keys);
    free(options);
}
