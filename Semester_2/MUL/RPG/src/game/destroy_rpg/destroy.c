/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** destroy
*/

#include "rpg.h"

static void inventory_destroy(void)
{
    for (int i = 0; i < 7; ++i)
        game_obj_destroy(rpg->inventory->image[i]);
    free(rpg->inventory->image);
    free(rpg->inventory);
}

static void cooldown_destroy(void)
{
    for (int i = 0; i <= 2; ++i)
        sfClock_destroy(rpg->player->cd_clock[i]);
    free(rpg->player->cd_clock);
    free(rpg->player->cd_sec);
    free(rpg->player->cd_time);
    free(rpg->player->is_able);
    free(rpg->player->cd_value);
}

static void window_destroy(void)
{
    options_destroy(rpg->options);
    for (int i = 0; rpg->scenes[i]; ++i)
        scene_destroy(rpg->scenes[i]);
    sfView_destroy(rpg->view);
    sfRenderWindow_destroy(rpg->window);
}
void rpg_destroy(rpg_t *rpg)
{
    inventory_destroy();
    cooldown_destroy();
    gameplay_destroy();
    window_destroy();
    free(rpg);
}
