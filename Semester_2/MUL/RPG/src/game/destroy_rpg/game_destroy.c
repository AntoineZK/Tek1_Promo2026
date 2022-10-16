/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** game_destroy
*/

#include "rpg.h"

static void effect_destroy(void)
{
    for (int i = 0; i < 40; ++i)
        particule_destroy(rpg->particules[i]);
    free(rpg->particules);
}

static void monsters_destroy(void)
{
    for (int i = 0; rpg->monsters[i]; ++i)
        monster_destroy(rpg->monsters[i]);
    free(rpg->monsters);
}

static void player_destroy(void)
{
    for (int i = 0; i <= 11; ++i)
        game_obj_destroy(rpg->player->image[i]);
    free(rpg->player->image);
    sfClock_destroy(rpg->player->clock);
    free(rpg->player->sword);
    free(rpg->player->is_dash);
    free(rpg->player->is_anim);
    free(rpg->player);
    free(rpg->joy);
}

static void view_map_destroy(void)
{
    sfView_destroy(rpg->mini_map->view);
    free(rpg->mini_map);
    sfView_destroy(rpg->info->view);
    free(rpg->info);
    if (rpg->in_game) {
        for (int i = 0; rpg->d_map[i]; ++i)
            array_destroy(rpg->d_map[i]);
        free(rpg->d_map);
        array_destroy(rpg->c_map);
    }
    game_obj_destroy(rpg->map1);
    game_obj_destroy(rpg->map2);
}

void gameplay_destroy(void)
{
    effect_destroy();
    for (int i = 0; rpg->npcs[i]; ++i)
        npc_destroy(rpg->npcs[i]);
    free(rpg->npcs);
    monsters_destroy();
    player_destroy();
    view_map_destroy();
}
