/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** rpg_obj2
*/

#include "rpg.h"

joystick_t *joystick_create(void)
{
    rpg->joy = malloc(sizeof(joystick_t));
    rpg->joy = my_memset(rpg->joy, 0, sizeof(joystick_t));
    rpg->joy->dash = 6;
    rpg->joy->minimap = 3;
    rpg->joy->pause = 9;
    rpg->joy->inventory = 2;
    rpg->joy->attack = 7;
    rpg->joy->mode = 5;
    rpg->joy->interact = 1;
    return (rpg->joy);
}

void cooldown_create(void)
{
    rpg->player->cd_clock = malloc(sizeof(sfClock *) * 3);
    rpg->player->cd_clock[DASH] = sfClock_create();
    rpg->player->cd_clock[SWORD] = sfClock_create();
    rpg->player->cd_clock[BOW] = sfClock_create();
    rpg->player->cd_sec = malloc(sizeof(float) * 3);
    for (int i = 0; i < 3; i++)
        rpg->player->cd_sec[i] = 0;
    rpg->player->cd_time = malloc(sizeof(sfTime) * 3);
    rpg->player->is_able = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
        rpg->player->is_able[i] = 1;
    rpg->player->cd_value = malloc(sizeof(float) * 3);
    rpg->player->cd_value[DASH] = 5;
    rpg->player->cd_value[SWORD] = 5;
    rpg->player->cd_value[BOW] = 5;
}

void sword_create(void)
{
    rpg->player->sword = malloc(sizeof(rpg->player->sword) * 4);
    rpg->player->sword = my_memset(rpg->player->sword, 0,
    sizeof(rpg->player->sword) * 4);
    rpg->player->image[SW_DOWN] = game_obj_create
    ("assets/player/sword_down.png", rpg->player->pos, "sw_down");
    rpg->player->image[SW_UP] = game_obj_create
    ("assets/player/sword_up.png", rpg->player->pos, "sw_up");
    rpg->player->image[SW_LEFT] = game_obj_create
    ("assets/player/sword_left.png", rpg->player->pos, "sw_left");
    rpg->player->image[SW_RIGHT] = game_obj_create
    ("assets/player/sword_right.png", rpg->player->pos, "sw_right");
    bow_create();
}

void dash_create(void)
{
    rpg->player->is_dash = malloc(sizeof(int) * 4);
    rpg->player->is_dash = my_memset(rpg->player->is_dash, 0, sizeof(int) * 4);
    rpg->player->is_dash_status = 0;
    cooldown_create();
    sword_create();
}

void create_particule(void)
{
    rpg->particules = malloc(sizeof(particule_t) * 40);
    rpg->particules = my_memset(rpg->particules, 0, sizeof(particule_t) * 40);
    for (int i = 0; i < 40; ++i) {
        rpg->particules[i] = particule_create(rand() % 2 ?
        sfColor_fromRGB(0, 255, 255) : sfColor_fromRGB(255, 255, 0), CIRCLE);
        rpg->particules[i]->color.a = 0;
        rpg->particules[i]->position = (sfVector2f) {-1, -1};
        sfShape_setPosition(rpg->particules[i]->shape,
        rpg->particules[i]->position);
        rpg->particules[i]->freeze = 1;
    }
}
