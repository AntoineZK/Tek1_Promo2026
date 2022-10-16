/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** monster_move
*/

#include "rpg.h"

void move_monster(monster_t *mstr, int movement)
{
    movement == MSTR_DOWN ? mstr->pos.y += 1 : 0;
    movement == MSTR_UP ? mstr->pos.y -= 1 : 0;
    movement == MSTR_LEFT ? mstr->pos.x -= 1 : 0;
    movement == MSTR_RIGHT ? mstr->pos.x += 1 : 0;
}

void monster_event(monster_t *mstr)
{
    if (!mstr->in_range) {
        if (mstr->moving_status == 100) {
            mstr->moving_status = 0;
            mstr->is_moving = rand() % 4;
            mstr->status = my_memset(mstr->status, 0, sizeof(int) * 4);
            mstr->status[mstr->is_moving] = 1;
        }
        move_monster(mstr, mstr->is_moving);
    }
    if (mstr->in_range) {
        if (!mstr->is_attacking) {
            mstr->moving_status >= 100 ? mstr->moving_status = 0 : 0;
            follow_player(rpg->player->pos, mstr->pos, mstr);
            set_angle_monster(mstr);
        } else {
            set_angle_monster(mstr);
        }
    }
}

static void set_angle_monster_two(monster_t *mstr)
{
    if ((mstr->angle > 100 && mstr->angle <= 180) ||
    (mstr->angle >= -180 && mstr->angle < -100)) {
        mstr->is_moving = MSTR_LEFT;
        mstr->status = my_memset(mstr->status, 0, sizeof(int) * 4);
        mstr->status[MSTR_LEFT] = 1;
    }
    if (mstr->angle < -80 && mstr->angle >= -100) {
        mstr->is_moving = MSTR_UP;
        mstr->status = my_memset(mstr->status, 0, sizeof(int) * 4);
        mstr->status[MSTR_UP] = 1;
    }
}

void set_angle_monster(monster_t *mstr)
{
    if ((mstr->angle >= 0 && mstr->angle <= 80) ||
    (mstr->angle >= -80 && mstr->angle < 0)) {
        mstr->is_moving = MSTR_RIGHT;
        mstr->status = my_memset(mstr->status, 0, sizeof(int) * 4);
        mstr->status[MSTR_RIGHT] = 1;
    }
    if (mstr->angle > 80 && mstr->angle <= 100) {
        mstr->is_moving = MSTR_DOWN;
        mstr->status = my_memset(mstr->status, 0, sizeof(int) * 4);
        mstr->status[MSTR_DOWN] = 1;
    }
    set_angle_monster_two(mstr);
}

void draw_mobs(void)
{
    for (int i = 0; rpg->monsters[i]; ++i) {
        if (rpg->monsters[i]->hp > 0) {
            rpg->monsters[i]->in_range =
            in_range(rpg->player->pos, rpg->monsters[i]->pos, 384);
            rpg->monsters[i]->is_attacking =
            in_range(rpg->player->pos, rpg->monsters[i]->pos, 64);
        }
    }
    for (int i = 0; rpg->monsters[i]; ++i) {
        if (rpg->monsters[i]->hp > 0) {
            monster_draw(rpg->monsters[i]);
            set_pos_monster(rpg->monsters[i]);
        }
    }
}
