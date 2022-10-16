/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** init_two
*/

#include "../include/defender.h"

void init_tuto_pause_two(defender_t *def)
{
    def->pause.p_sett = image_create("res/settings.png",
    (sfVector2f) {300, 800});
    def->pause.p_sett_o = image_create("res/settings_o.png",
    (sfVector2f) {300, 800});
    def->pause.p_return = image_create("res/back.png",
    (sfVector2f) {1350, 200});
    def->pause.p_return_o = image_create("res/back_o.png",
    (sfVector2f) {1350, 200});
}

void init_game_two(defender_t *def)
{
    def->game.g_heart = image_create("res/heart.png",
    (sfVector2f) {1575, 250});
    sfSprite_setTextureRect(def->game.g_heart->sprite,
    (sfIntRect) {0, 0, 100, 116});
    def->game.g_coin = image_create("res/coin.png",
    (sfVector2f) {1575, 160});
    sfSprite_setTextureRect(def->game.g_heart->sprite,
    (sfIntRect) {0, 0, 100, 116});
}
