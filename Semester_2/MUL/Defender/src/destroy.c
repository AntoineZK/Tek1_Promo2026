/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** destroy
*/

#include "../include/defender.h"

static void destroy_menu(defender_t *def)
{
    sfDestroy(def->menu.m_background);
    sfDestroy(def->menu.m_start);
    sfDestroy(def->menu.m_start_o);
    sfDestroy(def->menu.m_exit);
    sfDestroy(def->menu.m_exit_o);
    sfDestroy(def->menu.m_tuto);
    sfDestroy(def->menu.m_tuto_o);
    sfDestroy(def->menu.m_sett);
    sfDestroy(def->menu.m_sett_o);
}

static void destroy_settings_tuto(defender_t *def)
{
    sfDestroy(def->sett.s_background);
    sfDestroy(def->sett.s_return);
    sfDestroy(def->sett.s_return_o);
    sfDestroy(def->sett.s_minus);
    sfDestroy(def->sett.s_minus_o);
    sfDestroy(def->sett.s_plus);
    sfDestroy(def->sett.s_plus_o);
    sfDestroy(def->tuto.t_background);
    sfDestroy(def->tuto.t_return);
    sfDestroy(def->tuto.t_return_o);
}

static void destroy_pause(defender_t *def)
{
    sfDestroy(def->pause.p_background);
    sfDestroy(def->pause.p_exit);
    sfDestroy(def->pause.p_exit_o);
    sfDestroy(def->pause.p_resume);
    sfDestroy(def->pause.p_resume_o);
    sfDestroy(def->pause.p_return);
    sfDestroy(def->pause.p_return_o);
    sfDestroy(def->pause.p_sett);
    sfDestroy(def->pause.p_sett_o);
}

static void destroy_game(defender_t *def)
{
    sfDestroy(def->game.g_background);
    sfDestroy(def->game.g_fire_tow);
    sfDestroy(def->game.g_moula_tow);
    sfDestroy(def->game.g_slow_tow);
    sfDestroy(def->game.g_stone_tow);
    sfDestroy(def->game.g_redm_tow);
    sfDestroy(def->game.g_obe_tow);
    sfDestroy(def->game.g_upgrade);
    sfDestroy(def->game.g_coin);
    sfDestroy(def->game.g_heart);
    sfClock_destroy(def->c_heart);
    sfClock_destroy(def->c_coin);
}

void destroy_all(defender_t *def)
{
    destroy_menu(def);
    destroy_settings_tuto(def);
    destroy_pause(def);
    sfSoundBuffer_destroy(def->cbuffer);
    sfSound_destroy(def->csound);
    sfSoundBuffer_destroy(def->towbuffer);
    sfSound_destroy(def->towsound);
    sfClock_destroy(def->clock);
    destroy_game(def);
    sfMusic_destroy(def->music);
    sfView_destroy(def->cam);
    sfRenderWindow_destroy(def->wdw);
    free_all(def);
}
