/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** init
*/

#include "../include/defender.h"

static void init_menu(defender_t *def)
{
    def->menu.m_background = image_create("res/element.png",
    (sfVector2f) {0, 0});
    def->menu.m_start = image_create("res/start.png",
    (sfVector2f) {300, 200});
    def->menu.m_start_o = image_create("res/start_o.png",
    (sfVector2f) {300, 200});
    def->menu.m_exit = image_create("res/exit.png",
    (sfVector2f) {1350, 800});
    def->menu.m_exit_o = image_create("res/exit_o.png",
    (sfVector2f) {1350, 800});
    def->menu.m_sett = image_create("res/settings.png",
    (sfVector2f) {300, 800});
    def->menu.m_sett_o = image_create("res/settings_o.png",
    (sfVector2f) {300, 800});
    def->menu.m_tuto = image_create("res/tuto.png",
    (sfVector2f) {1350, 200});
    def->menu.m_tuto_o = image_create("res/tuto_o.png",
    (sfVector2f) {1350, 200});
}

static void init_settings(defender_t *def)
{
    def->sett.s_background = image_create("res/background.png",
    (sfVector2f) {0, 0});
    def->sett.s_return = image_create("res/back.png",
    (sfVector2f) {830, 800});
    def->sett.s_return_o = image_create("res/back_o.png",
    (sfVector2f) {830, 800});
    def->sett.s_minus = image_create("res/minus.png",
    (sfVector2f) {650, 200});
    def->sett.s_minus_o = image_create("res/minus_o.png",
    (sfVector2f) {650, 200});
    def->sett.s_plus = image_create("res/plus.png",
    (sfVector2f) {1190, 200});
    def->sett.s_plus_o = image_create("res/plus_o.png",
    (sfVector2f) {1190, 200});
}

static void init_tuto_pause(defender_t *def)
{
    def->tuto.t_background = image_create("res/background.png",
    (sfVector2f) {0, 0});
    def->tuto.t_return = image_create("res/back.png",
    (sfVector2f) {830, 800});
    def->tuto.t_return_o = image_create("res/back_o.png",
    (sfVector2f) {830, 800});
    def->pause.p_background = image_create("res/element.png",
    (sfVector2f) {0, 0});
    def->pause.p_resume = image_create("res/resume.png",
    (sfVector2f) {300, 200});
    def->pause.p_resume_o = image_create("res/resume_o.png",
    (sfVector2f) {300, 200});
    def->pause.p_exit = image_create("res/exit.png",
    (sfVector2f) {1350, 800});
    def->pause.p_exit_o = image_create("res/exit_o.png",
    (sfVector2f) {1350, 800});
    init_tuto_pause_two(def);
}

static void init_game(defender_t *def)
{
    def->game.g_background = image_create("res/background.png",
    (sfVector2f) {0, 0});
    def->game.g_fire_tow = image_create("res/cadre_fire.png",
    (sfVector2f) {1404, 610});
    def->game.g_stone_tow = image_create("res/cadre_stone.png",
    (sfVector2f) {1404 + 172, 610});
    def->game.g_slow_tow = image_create("res/cadre_slow.png",
    (sfVector2f) {1404 + 172, 845});
    def->game.g_moula_tow = image_create("res/cadre_moula.png",
    (sfVector2f) {1404, 845});
    def->game.g_obe_tow = image_create("res/cadre_obe.png",
    (sfVector2f) {1404 + 172 + 172, 610});
    def->game.g_redm_tow = image_create("res/cadre_redm.png",
    (sfVector2f) {1404 + 172 + 172, 845});
    def->game.g_upgrade = image_create("res/upgrade.png",
    (sfVector2f) {1404, 385});
    init_game_two(def);
}

void init_all(defender_t *defender)
{
    init_menu(defender);
    init_settings(defender);
    init_tuto_pause(defender);
    init_game(defender);
    defender->end = 0;
}
