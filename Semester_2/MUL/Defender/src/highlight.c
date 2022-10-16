/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** highlight
*/

#include "../include/defender.h"

void highlight_evt(defender_t *def, sfVector2f mou)
{
    def->hg.start_light = click_btton(def->menu.m_start, mou.x, mou.y) ? 1 : 0;
    def->hg.tuto_light = click_btton(def->menu.m_tuto, mou.x, mou.y) ? 1 : 0;
    def->hg.exit_light = click_btton(def->menu.m_exit, mou.x, mou.y) ? 1 : 0;
    def->hg.sett_light = click_btton(def->menu.m_sett, mou.x, mou.y) ? 1 : 0;
    def->hg.resume_light = click_btton(def->pause.p_resume, mou.x, mou.y)
    ? 1 : 0;
    def->hg.return_light = click_btton(def->pause.p_return, mou.x, mou.y)
    ? 1 : 0;
    def->hg.p_exit_light = click_btton(def->pause.p_exit, mou.x, mou.y)
    ? 1 : 0;
    def->hg.p_sett_light = click_btton(def->pause.p_sett, mou.x, mou.y)
    ? 1 : 0;
    def->hg.minus_light = click_btton(def->sett.s_minus, mou.x, mou.y) ? 1 : 0;
    def->hg.plus_light = click_btton(def->sett.s_plus, mou.x, mou.y) ? 1 : 0;
    def->hg.tuto_return = click_btton(def->tuto.t_return, mou.x, mou.y)
    ? 1 : 0;
    def->hg.sett_return = click_btton(def->sett.s_return, mou.x, mou.y)
    ? 1 : 0;
}
