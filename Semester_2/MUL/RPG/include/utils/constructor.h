/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** constructor
*/

#ifndef CONSTRUCTOR_H_
    #define CONSTRUCTOR_H_

    #include "rpg.h"
    #include "csfml.h"

sfSprite *constructor_sprite_game_obj(game_obj *game_obj, char const *image);
sfSprite *constructor_sprite_scene(scene *scene, char const *image);
sfSprite *constructor_sprite_button(button *button, char const *image);
sfColor constructor_rgba(char const *hexa);

#endif/* !CONSTRUCTOR_H_ */
