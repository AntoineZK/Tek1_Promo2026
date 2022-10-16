/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** xml_game_obj
*/

#include "utils/xml.h"

game_obj *xml_game_obj_parser(char **content)
{
    game_obj *game_obj = game_obj_create_empty();
    while ((*(*content)) != '>') {
        if (!is_alpha(content))
            continue;
        char *param = xml_get_param(content);
        char *value = xml_get_value(content);
        if (my_str_is_equal(param, "name"))
            game_obj->name = my_strcpy(value);
        if (my_str_is_equal(param, "image"))
            game_obj->sprite = constructor_sprite_game_obj(game_obj, value);
        if (my_str_is_equal(param, "x"))
            game_obj->position = (sfVector2f) {my_getnbr(value),
            game_obj->position.y};
        if (my_str_is_equal(param, "y"))
            game_obj->position = (sfVector2f) {game_obj->position.x,
            my_getnbr(value)};
        free(param);
    }
    sfSprite_setPosition(game_obj->sprite, game_obj->position);
    return (game_obj);
}
