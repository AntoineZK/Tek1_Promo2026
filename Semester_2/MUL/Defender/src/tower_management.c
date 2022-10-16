/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** tower_mangement
*/

#include "../include/defender.h"

static void cond_update(defender_t *def, int back_x, int back_y, int i)
{
    if ((back_x /= 108) == def->x_int && (back_y /= 108) == def->y_int
    && def->ts->tow_id <= 11) {
        def->node_val = i;
        def->to_up = 1;
    }
}

static void find_tower(defender_t *def, double x, double y)
{
    int back_x = 0;
    int back_y = 0;
    double_to_int(def, x, y);
    tower_t *backup = def->ts;
    if (def->map[def->y_int][def->x_int] == '9') {
        for (int i = 0; def->ts; def->ts = def->ts->next, i++) {
            back_x = def->ts->pos.x;
            back_y = def->ts->pos.y;
            cond_update(def, back_x, back_y, i);
        }
        def->ts = backup;
    }
}

static void able_place_tower(defender_t *def, double x, double y)
{
    click_btton(def->game.g_fire_tow, x, y) && def->scene == GAME
    ? def->ctower = FIRE : 0;
    click_btton(def->game.g_stone_tow, x, y) && def->scene == GAME
    ? def->ctower = STONE : 0;
    click_btton(def->game.g_moula_tow, x, y) && def->scene == GAME
    ? def->ctower = MOULA : 0;
    click_btton(def->game.g_slow_tow, x, y) && def->scene == GAME
    ? def->ctower = SLOW : 0;
    click_btton(def->game.g_redm_tow, x, y) && def->scene == GAME
    ? def->ctower = REDMOON : 0;
    click_btton(def->game.g_obe_tow, x, y) && def->scene == GAME
    ? def->ctower = OBE : 0;
}

void place_tower(defender_t *def, double x, double y)
{
    able_place_tower(def, x, y);
    if (def->ctower != 1000 && def->scene == GAME && find_char_map(def, x, y)
    == '0' && def->money >= def->price_tow[def->ctower]) {
        if (def->ctower == OBE)
            tower_add(def, my_stwa(def->tower_list[def->ctower],' ', '\0'),
            center_tower(x, y), (sfIntRect[1]) {{0, 0, 108, 108}});
        else if (def->ctower == REDMOON)
            tower_add(def, my_stwa(def->tower_list[def->ctower],' ', '\0'),
            center_tower(x, y), ((sfIntRect[1]) {{0, 0, 85, 108}}));
        else {
            tower_add(def, my_stwa(def->tower_list[def->ctower],' ', '\0'),
            center_tower(x, y), NULL);
        }
        def->money -= def->price_tow[def->ctower];
        def->ctower = 8;
        double_to_int(def, x, y);
        sfSound_play(def->towsound);
        def->map[def->y_int][def->x_int] = '9';
    }
    find_tower(def, x, y);
}

void tower_upgrade(defender_t *def, double x, double y)
{
    tower_t *backup = def->ts;
    for (int i = 0; i < def->node_val; i++, def->ts = def->ts->next);
    if (click_btton(def->game.g_upgrade, x, y) && def->to_up == 1
    && def->money >= def->price_tow[def->ts->tow_id]) {
        def->money -= def->price_tow[def->ts->tow_id + 6];
        if (def->ts->tow_id + 6 == REDMOON2 || def->ts->tow_id + 6 == REDMOON3)
            def->ts->tow_id + 6 <= 17 ? tower_update(def, my_stwa
            (def->tower_list[def->ts->tow_id + 6], ' ', '\0'),
            ((sfIntRect[1]) {{0, 0, 85, 108}})) : 0;
        else if (def->ts->tow_id + 6 == OBE2 || def->ts->tow_id + 6 == OBE3)
            def->ts->tow_id + 6 <= 17 ? tower_update(def, my_stwa
            (def->tower_list[def->ts->tow_id + 6], ' ', '\0'),
            (sfIntRect[1]) {{0, 0, 108, 108}}) : 0;
        else
            def->ts->tow_id + 6 <= 17 ? tower_update(def, my_stwa
            (def->tower_list[def->ts->tow_id + 6], ' ', '\0'),
            (sfIntRect[1]) {{0, 0, 108, 108}}) : 0;
        def->to_up = 0;
    }
    def->ts = backup;
}
