/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** button_position
*/

#include "game/game_obj.h"

void game_obj_set_position(game_obj *game_obj, int x, int y)
{
    game_obj->position.x = x;
    game_obj->position.y = y;
    sfSprite_setPosition(game_obj->sprite, game_obj->position);
}

void game_obj_move(game_obj *game_obj, int x, int y)
{
    game_obj->position.x += x;
    game_obj->position.y += y;
    sfSprite_setPosition(game_obj->sprite, game_obj->position);
}
