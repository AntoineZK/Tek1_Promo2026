/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** draw_game
*/

#include "rpg.h"

void draw_game(void)
{
    DRAW_SPRITE(rpg->window, rpg->map1->sprite);
    DRAW_SPRITE(rpg->window, rpg->map2->sprite);
    player_draw();
    set_pos_player();
    draw_mobs();
    cooldown();
    player_event();
    for (int i = 0; rpg->monsters[i]; ++i) {
        if (rpg->monsters[i]->hp > 0)
            monster_event(rpg->monsters[i]);
    }
    collision();
    rpg->player->is_able[BOW] == 0 ? arrow_launch() : 0;
    if (check_particules_alive())
        generate_particules(rpg->player->arrow_last_pos);
    particule_launch();
    draw_npc();
}

static void draw_text_one(void)
{
    float nda = rpg->player->cd_value[DASH] - rpg->player->cd_sec[DASH];
    float nsw = rpg->player->cd_value[SWORD] - rpg->player->cd_sec[SWORD];
    char *tmp2 = NULL;
    char *tmp3 = NULL;

    if (rpg->player->is_able[DASH])
        d_text_col(rpg->window, "ON", (sfVector2f) {150, 50}, sfRed);
    else {
        tmp2 = my_ftoa(nda);
        d_text_col(rpg->window, tmp2, (sfVector2f) {150, 50}, sfRed);
        free(tmp2);
    }
    if (rpg->player->is_able[SWORD])
        d_text_col(rpg->window, "ON", (sfVector2f) {175, 100}, sfRed);
    else {
        tmp3 = my_ftoa(nsw);
        d_text_col(rpg->window, tmp3, (sfVector2f) {175, 100}, sfRed);
        free(tmp3);
    }
}

static void draw_text_two(void)
{
    char *tmp = NULL;
    float nbw = rpg->player->cd_value[BOW] - rpg->player->cd_sec[BOW];

    if (rpg->player->is_able[BOW] == 1)
        d_text_col(rpg->window, "ON", (sfVector2f) {150, 150}, sfRed);
    if (rpg->player->is_able[BOW] == 2 || rpg->player->is_able[BOW] == 0) {
        tmp = my_ftoa(nbw);
        d_text_col(rpg->window, tmp, (sfVector2f) {150, 150}, sfRed);
        free(tmp);
    }
}

void draw_info(void)
{
    char *tmp = my_int_to_char(rpg->player->life);
    sfView_setCenter(rpg->info->view, (sfVector2f) {960, 540});
    sfView_setViewport(rpg->info->view, (sfFloatRect) {0, 0, 1, 1});
    sfRenderWindow_setView(rpg->window, rpg->info->view);
    d_text_col(rpg->window, "HP : ", (sfVector2f) {0, 0}, sfRed);
    d_text_col(rpg->window, tmp, (sfVector2f) {150, 0}, sfRed);
    d_text_col(rpg->window, "DASH : ", (sfVector2f) {0, 50}, sfRed);
    d_text_col(rpg->window, "SWORD : ", (sfVector2f) {0, 100}, sfRed);
    d_text_col(rpg->window, "BOW : ", (sfVector2f) {0, 150}, sfRed);
    draw_text_one();
    draw_text_two();
    free(tmp);
}

void draw_minimap(void)
{
    sfView_setCenter(rpg->mini_map->view, rpg->player->pos);
    sfView_setViewport(rpg->mini_map->view, rpg->mini_map->rect);
    sfRenderWindow_setView(rpg->window, rpg->mini_map->view);
    draw_game();
}
