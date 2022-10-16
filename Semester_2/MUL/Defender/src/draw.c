/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** draw
*/

#include "../include/defender.h"

void draw_menu(defender_t *def)
{
    draw_sprite(def, def->menu.m_background);
    if (def->hg.start_light == 0)
        draw_sprite(def, def->menu.m_start);
    else
        draw_sprite(def, def->menu.m_start_o);
    if (def->hg.tuto_light == 0)
        draw_sprite(def, def->menu.m_tuto);
    else
        draw_sprite(def, def->menu.m_tuto_o);
    if (def->hg.exit_light == 0)
        draw_sprite(def, def->menu.m_exit);
    else
        draw_sprite(def, def->menu.m_exit_o);
    if (def->hg.sett_light == 0)
        draw_sprite(def, def->menu.m_sett);
    else
        draw_sprite(def, def->menu.m_sett_o);
}

void draw_game(defender_t *def, map_t *game)
{
    char *up_price = "";
    draw_sprite(def, def->game.g_background);
    text_game(def, game);
    mob_loop(def);
    tower_loop(def);
    draw_sprite(def, def->game.g_fire_tow);
    draw_sprite(def, def->game.g_stone_tow);
    draw_sprite(def, def->game.g_slow_tow);
    draw_sprite(def, def->game.g_moula_tow);
    draw_sprite(def, def->game.g_obe_tow);
    draw_sprite(def, def->game.g_redm_tow);
    animation_coin(def);
    animation_heart(def);
    upgrade_text(def, up_price);
    price_tower_one(def);
    if (def->life <= 0)
        def->end = 2;
}

void draw_tuto(defender_t *def)
{
    draw_sprite(def, def->tuto.t_background);
    display_text(def, "Your goal in the Element Defense is to pass\n\
    through all the wave made of monster by killing them with\n\
    different tower, fire, OBE, slow, stone, redmoon, moula, each\n\
    one have different power such as slow ennemies, pierce ennemy armor,\n\
    max range tower, triple target, give moula, and do normal damage\n\
    each tower have evolution who's going to increase their statistic.\n\
    We Hope that you're going to get fun by playing at our game.\n\
    \n\n\
    Made by Antoine Khalidy and Yoan Gerard !",
    (sfVector2f) {0, 0}, 50);
    if (def->hg.tuto_return == 0)
        draw_sprite(def, def->tuto.t_return);
    else
        draw_sprite(def, def->tuto.t_return_o);
}

void draw_pause(defender_t *def)
{
    draw_sprite(def, def->pause.p_background);
    if (def->hg.resume_light == 0)
        draw_sprite(def, def->pause.p_resume);
    else
        draw_sprite(def, def->pause.p_resume_o);
    if (def->hg.return_light == 0)
        draw_sprite(def, def->pause.p_return);
    else
        draw_sprite(def, def->pause.p_return_o);
    if (def->hg.p_exit_light == 0)
        draw_sprite(def, def->pause.p_exit);
    else
        draw_sprite(def, def->pause.p_exit_o);
    if (def->hg.p_sett_light == 0)
        draw_sprite(def, def->pause.p_sett);
    else
        draw_sprite(def, def->pause.p_sett_o);
}
