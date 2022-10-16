/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** move
*/

#include "rpg.h"

static void set_move(int dir)
{
    rpg->player->last_pose = rpg->player->pos;
    rpg->player->status = dir;
    dir == 0 ? rpg->player->pos.y += 5 : 0;
    dir == 1 ? rpg->player->pos.y -= 5 : 0;
    dir == 2 ? rpg->player->pos.x -= 5 : 0;
    dir == 3 ? rpg->player->pos.x += 5 : 0;
    rpg->player->is_anim[dir] = 1;
}

void move_keyboard(void)
{
    if (sfKeyboard_isKeyPressed(rpg->options->keys[DOWN_KEY]))
        set_move(DOWN);
    else
        rpg->player->is_anim[DOWN] = 0;
    if (sfKeyboard_isKeyPressed(rpg->options->keys[UP_KEY]))
        set_move(UP);
    else
        rpg->player->is_anim[UP] = 0;
    if (sfKeyboard_isKeyPressed(rpg->options->keys[LEFT_KEY]))
        set_move(LEFT);
    else
        rpg->player->is_anim[LEFT] = 0;
    if (sfKeyboard_isKeyPressed(rpg->options->keys[RIGHT_KEY]))
        set_move(RIGHT);
    else
        rpg->player->is_anim[RIGHT] = 0;
}

void move_joystick(void)
{
    if (rpg->joy->joy1.y > 0)
        set_move(DOWN);
    else
        rpg->player->is_anim[DOWN] = 0;
    if (rpg->joy->joy1.y < 0)
        set_move(UP);
    else
        rpg->player->is_anim[UP] = 0;
    if (rpg->joy->joy1.x < 0)
        set_move(LEFT);
    else
        rpg->player->is_anim[LEFT] = 0;
    if (rpg->joy->joy1.x > 0)
        set_move(RIGHT);
    else
        rpg->player->is_anim[RIGHT] = 0;
}
