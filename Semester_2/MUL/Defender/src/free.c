/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** free
*/

#include "../include/defender.h"

static void free_menu(defender_t *def)
{
    free(def->menu.m_background);
    free(def->menu.m_start);
    free(def->menu.m_start_o);
    free(def->menu.m_exit);
    free(def->menu.m_exit_o);
    free(def->menu.m_tuto);
    free(def->menu.m_tuto_o);
    free(def->menu.m_sett);
    free(def->menu.m_sett_o);
}

static void free_settings(defender_t *def)
{
    free(def->sett.s_background);
    free(def->sett.s_minus);
    free(def->sett.s_minus_o);
    free(def->sett.s_plus);
    free(def->sett.s_plus_o);
    free(def->sett.s_return);
    free(def->sett.s_return_o);
    free(def->tuto.t_background);
    free(def->tuto.t_return);
    free(def->tuto.t_return_o);
}

static void free_pause(defender_t *def)
{
    free(def->pause.p_background);
    free(def->pause.p_exit);
    free(def->pause.p_exit_o);
    free(def->pause.p_resume);
    free(def->pause.p_return);
    free(def->pause.p_resume_o);
    free(def->pause.p_return_o);
    free(def->pause.p_sett);
    free(def->pause.p_sett_o);
}

static void free_game(defender_t *def)
{
    free(def->game.g_background);
    free(def->game.g_fire_tow);
    free(def->game.g_moula_tow);
    free(def->game.g_slow_tow);
    free(def->game.g_stone_tow);
    free(def->game.g_redm_tow);
    free(def->game.g_obe_tow);
    free(def->game.g_upgrade);
    free(def->game.g_coin);
    free(def->game.g_heart);
}

void free_all(defender_t *def)
{
    free_menu(def);
    free_settings(def);
    free_pause(def);
    free_game(def);
    free_double_array(def->wave_list);
    free_double_array(def->tower_list);
    free_double_array(def->map);
    free_tower(def->ts);
    free_mobs(def->mobs);
    if (def->mob_text != NULL)
        sfTexture_destroy(def->mob_text);
    free(def->cmap);
    free(def);
}
