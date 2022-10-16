/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** constructor
*/

#include "utils/constructor.h"

sfSprite *constructor_sprite_game_obj(game_obj *game_obj, char const *image)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(image, NULL);
    game_obj->texture = texture;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfSprite *constructor_sprite_scene(scene *scene, char const *image)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(image, NULL);
    scene->texture = texture;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfSprite *constructor_sprite_button(button *button, char const *image)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(image, NULL);
    button->texture = texture;
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

sfColor constructor_rgba(char const *hexa)
{
    int red = my_hexa_to_int((char[3]) {hexa[0], hexa[1], 0});
    int blue = my_hexa_to_int((char[3]) {hexa[2], hexa[3], 0});
    int green = my_hexa_to_int((char[3]) {hexa[4], hexa[5], 0});
    int alpha = my_hexa_to_int((char[3]) {hexa[6], hexa[7], 0});
    return (sfColor_fromRGBA(red, green, blue, alpha));
}
