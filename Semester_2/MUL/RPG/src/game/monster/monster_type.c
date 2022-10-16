/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** monster_tyoe
*/

#include "rpg.h"

static monster_t *set_value(monster_t *mstr, int *value, sfVector2f pos)
{
    mstr->is_moving = MSTR_DOWN;
    mstr->clock = sfClock_create();
    mstr->sec = 0;
    mstr->damage = value[0];
    mstr->hp = value[1];
    mstr->speed = value[2];
    mstr->xp = value[3];
    mstr->len = value[4];
    mstr->rect = (sfIntRect) {128, 0, 128, 128};
    mstr->pos = pos;
    mstr->moving_status = 0;
    mstr->in_range = 0;
    mstr->status = malloc(sizeof(int) * 4);
    mstr->status = my_memset(mstr->status, 0, sizeof(int) * 4);
    mstr->status[DOWN] = 1;
    return (mstr);
}

monster_t *type_skeleton(monster_t *mstr, sfVector2f pos)
{
    mstr = set_value(mstr, (int[]) {10, 10, 1, 100, 768}, pos);
    mstr->obj = malloc(sizeof(game_obj *) * 8);
    mstr->obj[MSTR_DOWN] = monster_create("assets/monster_1/move_down.png",
    pos, mstr->rect);
    mstr->obj[MSTR_UP] = monster_create("assets/monster_1/move_up.png",
    pos, mstr->rect);
    mstr->obj[MSTR_LEFT] = monster_create("assets/monster_1/move_left.png",
    pos, mstr->rect);
    mstr->obj[MSTR_RIGHT] = monster_create("assets/monster_1/move_right.png",
    pos, mstr->rect);
    mstr->obj[MSTR_AT_DOWN] = monster_create(
        "assets/monster_1/attack_down.png", pos, mstr->rect);
    mstr->obj[MSTR_AT_UP] = monster_create("assets/monster_1/attack_up.png",
    pos, mstr->rect);
    mstr->obj[MSTR_AT_LEFT] = monster_create(
        "assets/monster_1/attack_left.png", pos, mstr->rect);
    mstr->obj[MSTR_AT_RIGHT] = monster_create(
        "assets/monster_1/attack_right.png", pos, mstr->rect);
    return (mstr);
}

static monster_t *set_value_2(monster_t *mstr, int *value, sfVector2f pos)
{
    mstr->is_moving = MSTR_DOWN;
    mstr->clock = sfClock_create();
    mstr->sec = 0;
    mstr->damage = value[0];
    mstr->hp = value[1];
    mstr->speed = value[2];
    mstr->xp = value[3];
    mstr->len = value[4];
    mstr->rect = (sfIntRect) {1020, 0, 1020, 255};
    mstr->pos = pos;
    mstr->moving_status = 0;
    mstr->in_range = 0;
    mstr->status = malloc(sizeof(int) * 4);
    mstr->status = my_memset(mstr->status, 0, sizeof(int) * 4);
    mstr->status[DOWN] = 1;
    return (mstr);
}

monster_t *type_boss(monster_t *mstr, sfVector2f pos)
{
    mstr = set_value_2(mstr, (int[]) {10, 10, 1, 100, 768}, pos);
    mstr->obj = malloc(sizeof(game_obj *) * 8);
    mstr->obj[MSTR_DOWN] = monster_create("assets/boss/boss_down.png",
    pos, mstr->rect);
    mstr->obj[MSTR_UP] = monster_create("assets/boss/boss_down.png",
    pos, mstr->rect);
    mstr->obj[MSTR_LEFT] = monster_create("assets/boss/boss_down.png",
    pos, mstr->rect);
    mstr->obj[MSTR_RIGHT] = monster_create("assets/boss/boss_down.png",
    pos, mstr->rect);
    mstr->obj[MSTR_AT_DOWN] = monster_create(
        "assets/boss/boss_down.png", pos, mstr->rect);
    mstr->obj[MSTR_AT_UP] = monster_create("assets/boss/boss_down.png",
    pos, mstr->rect);
    mstr->obj[MSTR_AT_LEFT] = monster_create(
        "assets/boss/boss_down.png", pos, mstr->rect);
    mstr->obj[MSTR_AT_RIGHT] = monster_create(
        "assets/boss/boss_down.png", pos, mstr->rect);
    return (mstr);
}
