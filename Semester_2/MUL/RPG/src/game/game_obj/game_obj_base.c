/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** game_obj
*/

#include "game/game_obj.h"

game_obj *game_obj_create_empty(void)
{
    game_obj *game_obj = malloc(sizeof(struct game_obj));
    game_obj->name = NULL;
    game_obj->position = (sfVector2f) {0};
    game_obj->size = (sfVector2u) {0};
    game_obj->sprite = NULL;
    game_obj->texture = NULL;
    game_obj->display = 0;
    return (game_obj);
}

game_obj *game_obj_create(char const *texture_name, sfVector2f position,
char *name)
{
    game_obj *game_obj = malloc(sizeof(struct game_obj));
    game_obj->sprite = sfSprite_create();
    game_obj->position = position;
    game_obj->texture = sfTexture_createFromFile(texture_name, NULL);
    sfSprite_setTexture(game_obj->sprite, game_obj->texture, sfTrue);
    game_obj->size.x = sfSprite_getTextureRect(game_obj->sprite).width;
    game_obj->size.y = sfSprite_getTextureRect(game_obj->sprite).height;
    game_obj->name = my_strcpy(name);
    sfSprite_setPosition(game_obj->sprite, game_obj->position);
    return (game_obj);
}

void game_obj_set_rect(game_obj *game_obj, sfIntRect rect)
{
    sfSprite_setTextureRect(game_obj->sprite, rect);
    int width = sfSprite_getTextureRect(game_obj->sprite).width;
    int height = sfSprite_getTextureRect(game_obj->sprite).height;
    game_obj->size = (sfVector2u) {width, height};
}

void game_obj_set_scale(game_obj *game_obj, sfVector2f scale)
{
    sfSprite_setScale(game_obj->sprite, scale);
    int width = sfSprite_getTextureRect(game_obj->sprite).width;
    int height = sfSprite_getTextureRect(game_obj->sprite).height;
    game_obj->size = (sfVector2u) {width, height};
}

void game_obj_destroy(game_obj *game_obj)
{
    free(game_obj->name);
    sfSprite_destroy(game_obj->sprite);
    sfTexture_destroy(game_obj->texture);
    free(game_obj);
}
