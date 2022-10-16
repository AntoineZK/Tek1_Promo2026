/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** event
*/

#include "../include/defender.h"

void menu_button(defender_t *def, double x, double y)
{
    if (click_btton(def->menu.m_start, x, y) && (def->scene == MENU)) {
        sfSound_play(def->csound);
        def->scene = GAME;
    }
    if (click_btton(def->menu.m_sett, x, y) && (def->scene == MENU)) {
        sfSound_play(def->csound);
        def->scene = SETTINGS;
    }
    if (click_btton(def->menu.m_exit, x, y) && (def->scene == MENU)) {
        sfSound_play(def->csound);
        sfRenderWindow_close(def->wdw);
    }
    if (click_btton(def->menu.m_tuto, x, y) && (def->scene == MENU)) {
        sfSound_play(def->csound);
        def->scene = TUTO;
    }
}

void settings_button(defender_t *def, double x, double y)
{
    if (click_btton(def->sett.s_minus_o, x, y) && (def->scene == SETTINGS)) {
        sfSound_play(def->csound);
        def->volume -= 10;
    }
    if (click_btton(def->sett.s_plus_o, x, y) && (def->scene == SETTINGS)) {
        sfSound_play(def->csound);
        def->volume += 10;
    }
    if (click_btton(def->sett.s_return, x, y) && (def->scene == SETTINGS)) {
        sfSound_play(def->csound);
        def->scene = MENU;
    }
}

void tuto_button(defender_t *def, double x, double y)
{
    if (click_btton(def->tuto.t_return, x, y) && (def->scene == TUTO)) {
        sfSound_play(def->csound);
        def->scene = MENU;
    }
}

void pause_button(defender_t *def, double x, double y)
{
    if (click_btton(def->pause.p_resume, x, y) && (def->scene == PAUSE)) {
        sfSound_play(def->csound);
        def->scene = GAME;
    }
    if (click_btton(def->pause.p_return, x, y) && (def->scene == PAUSE)) {
        def->wave = 0;
        sfSound_play(def->csound);
        def->scene = MENU;
    }
    if (click_btton(def->pause.p_sett, x, y) && (def->scene == PAUSE)) {
        sfSound_play(def->csound);
        def->scene = SETTINGS;
    }
    if (click_btton(def->pause.p_exit, x, y) && (def->scene == PAUSE)) {
        sfRenderWindow_close(def->wdw);
    }
}

void defender_event(defender_t *def)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(def->wdw);
    sfVector2f cam_mouse = sfRenderWindow_mapPixelToCoords
    (def->wdw, mouse, def->cam);
    if (def->event.type == sfEvtClosed)
        sfRenderWindow_close(def->wdw);
    if (def->event.type == sfEvtKeyPressed) {
        if ((def->event.key.code == sfKeyEscape) && (def->scene == GAME))
            def->scene = PAUSE;
        else if (def->event.key.code == sfKeyEscape)
            sfRenderWindow_close(def->wdw);
    }
    highlight_evt(def, cam_mouse);
    if (def->event.type == sfEvtMouseButtonPressed) {
        menu_button(def, cam_mouse.x, cam_mouse.y);
        settings_button(def, cam_mouse.x, cam_mouse.y);
        tuto_button(def, cam_mouse.x, cam_mouse.y);
        pause_button(def, cam_mouse.x, cam_mouse.y);
        place_tower(def, cam_mouse.x, cam_mouse.y);
        tower_upgrade(def, cam_mouse.x, cam_mouse.y);
    }
}
