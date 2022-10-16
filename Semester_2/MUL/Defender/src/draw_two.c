/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** draw_two
*/

#include "../include/defender.h"

static void draw_settings_two(defender_t *def)
{
    if (def->hg.sett_return == 0)
        draw_sprite(def, def->sett.s_return);
    else
        draw_sprite(def, def->sett.s_return_o);
    if (def->hg.minus_light == 0)
        draw_sprite(def, def->sett.s_minus);
    else
        draw_sprite(def, def->sett.s_minus_o);
    if (def->hg.plus_light == 0)
        draw_sprite(def, def->sett.s_plus);
    else
        draw_sprite(def, def->sett.s_plus_o);
}

void draw_settings(defender_t *def)
{
    char *volume = NULL;
    def->volume <= 0 ? def->volume = 0 : 0;
    def->volume >= 100 ? def->volume = 100 : 0;
    sfMusic_setVolume(def->music, def->volume);
    volume = int_to_char(def->volume);
    draw_sprite(def, def->sett.s_background);
    display_text(def, "Volume =", (sfVector2f) {820, 200}, 50);
    display_text(def, volume, (sfVector2f) {1060, 200}, 50);
    draw_settings_two(def);
    free(volume);
}
