/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** animation
*/

#include "../include/my.h"
#include "../include/myhunter.h"

void moving_goblin(sfSprite *sprite)
{
    sfVector2f direction = sfSprite_getPosition(sprite);
    direction.x += 18;
    direction.y += 0;
    sfSprite_setPosition(sprite, direction);
}

void animation_goblin(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 200;
    if (rect.left == 1200)
        rect.left = 0;
    rect.height = 190;
    rect.width = 200;
    sfSprite_setTextureRect(sprite, rect);
}

void moving_wyvern(sfSprite *sprite)
{
    sfVector2f direction = sfSprite_getPosition(sprite);
    direction.x += 18;
    direction.y += 0;
    sfSprite_setPosition(sprite, direction);
}

void animation_wyvern(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 200;
    if (rect.left == 1200)
        rect.left = 0;
    rect.height = 190;
    rect.width = 185;
    sfSprite_setTextureRect(sprite, rect);
}
