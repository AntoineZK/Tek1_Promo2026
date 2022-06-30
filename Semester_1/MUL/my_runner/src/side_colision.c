/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_colision
*/

#include "../include/my.h"
#include "../include/myrunner.h"

int right_collision(spritesheet_t *character, spritesheet_t *map, float x)
{
    sfIntRect character_size = sfSprite_getTextureRect(character->sprite);
    sfIntRect map_size = sfSprite_getTextureRect(map->sprite);
    if (character->position.x + character_size.width <= map->position.x &&
    character->position.x + character_size.width + x >= map->position.x &&
    character->position.x < map->position.x + map_size.width) {
        if (character->position.y + character_size.height - 1 >=
        map->position.y &&
        character->position.y <= map->position.y + map_size.height) {
            character->position.x -= x;
            return (1);
        }
    }
    return (0);
}

int top_collision(spritesheet_t *character, spritesheet_t *map, float y)
{
    sfIntRect map_size = sfSprite_getTextureRect(map->sprite);
    if (character->position.x >= map->position.x &&
    character->position.x <= map->position.x + map_size.width) {
        if (character->position.y >= map->position.y &&
        character->position.y - y <= map->position.y + map_size.height) {
            character->position.y = map->position.y + map_size.height;
            return (1);
        }
    }
    return (0);
}

int bottom_collision(spritesheet_t *character, spritesheet_t *map, float y)
{
    sfIntRect character_size = sfSprite_getTextureRect(character->sprite);
    sfIntRect map_size = sfSprite_getTextureRect(map->sprite);
    if (character->position.x + character_size.width >= map->position.x &&
    character->position.x <= map->position.x + map_size.width) {
        if (character->position.y <= map->position.y &&
            character->position.y + y + character_size.height >=\
            map->position.y) {
            character->position.y = map->position.y - character_size.height;
            return (1);
        }
    }
    return (0);
}
