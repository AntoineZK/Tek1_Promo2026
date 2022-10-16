/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** dash
*/

#include "rpg.h"

static void set_dash(int dir)
{
    rpg->player->last_pose = rpg->player->pos;
    rpg->player->status = dir;
    dir == 0 ? rpg->player->pos.y += 5 : 0;
    dir == 1 ? rpg->player->pos.y -= 5 : 0;
    dir == 2 ? rpg->player->pos.x -= 5 : 0;
    dir == 3 ? rpg->player->pos.x += 5 : 0;
    rpg->player->pos = walls(rpg->player->pos, rpg->player->is_anim, 5, 124);
    if (rpg->player->pos.x == rpg->player->last_pose.x &&
        rpg->player->pos.y == rpg->player->last_pose.y) {
        rpg->player->is_dash = my_memset(rpg->player->is_dash,
        0, sizeof(int) * 4);
        rpg->player->is_dash_status = 100;
        return;
    } else {
        rpg->player->is_dash[dir] = 1;
        rpg->player->is_dash_status++;
    }
    rpg->player->is_able[DASH] = 0;
}

void dash(int movement)
{
    while (rpg->player->is_dash_status < 100) {
        set_dash(movement);
        set_pos_player();
        dash_animation(rpg->player->image[movement], 1024);
    }
    rpg->player->is_dash = my_memset(rpg->player->is_dash, 0, sizeof(int) * 4);
    rpg->player->is_dash_status = 0;
}

void dash_keyboard(void)
{
    if (sfKeyboard_isKeyPressed(rpg->options->keys[DASH_KEY]) &&
    rpg->player->is_able[DASH]) {
        if (sfKeyboard_isKeyPressed(rpg->options->keys[DOWN_KEY]))
            set_dash(DOWN);
        else
            rpg->player->is_anim[DOWN] = 0;
        if (sfKeyboard_isKeyPressed(rpg->options->keys[UP_KEY]))
            set_dash(UP);
        else
            rpg->player->is_anim[UP] = 0;
        if (sfKeyboard_isKeyPressed(rpg->options->keys[LEFT_KEY]))
            set_dash(LEFT);
        else
            rpg->player->is_anim[LEFT] = 0;
        if (sfKeyboard_isKeyPressed(rpg->options->keys[RIGHT_KEY]))
            set_dash(RIGHT);
        else
            rpg->player->is_anim[RIGHT] = 0;
    }
}

void dash_joystick(void)
{
    if (sfJoystick_isButtonPressed(0 , rpg->joy->dash) &&
    rpg->player->is_able[DASH]) {
        if (rpg->joy->joy1.y > 0)
            set_dash(DOWN);
        else
            rpg->player->is_anim[DOWN] = 0;
        if (rpg->joy->joy1.y < 0)
            set_dash(UP);
        else
            rpg->player->is_anim[UP] = 0;
        if (rpg->joy->joy1.x < 0)
            set_dash(LEFT);
        else
            rpg->player->is_anim[LEFT] = 0;
        if (rpg->joy->joy1.x > 0)
            set_dash(RIGHT);
        else
            rpg->player->is_anim[RIGHT] = 0;
    }
}
