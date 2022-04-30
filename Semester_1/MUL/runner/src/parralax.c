/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** parralax
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void parralax_nbone(runner_t *runner)
{
    if (runner->parralax_one->position.x + sfTexture_getSize( \
    runner->parralax_one->texture).x <= 0) {
        sfSprite_setPosition(runner->parralax_one->sprite, \
        (sfVector2f) {1900, 0}) ;
        runner->parralax_one->position.x = 1900;
    }
    if (sfSprite_getPosition(runner->parralax_one->sprite_copy).x + \
    sfTexture_getSize(runner->parralax_one->texture).x <= 0) {
        sfSprite_setPosition(runner->parralax_one->sprite_copy, \
        (sfVector2f) {1900, 0});
    }
    sfRenderWindow_drawSprite(runner->window, \
    runner->parralax_one->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window, \
    runner->parralax_one->sprite_copy, NULL);
}

void parralax_nbtwo(runner_t *runner)
{
    if (runner->parralax_two->position.x + sfTexture_getSize( \
    runner->parralax_two->texture).x <= 0) {
        sfSprite_setPosition(runner->parralax_two->sprite, \
        (sfVector2f) {1900, 0}) ;
        runner->parralax_two->position.x = 1900;
    }
    if (sfSprite_getPosition(runner->parralax_two->sprite_copy).x + \
    sfTexture_getSize( runner->parralax_two->texture).x <= 0) {
        sfSprite_setPosition(runner->parralax_two->sprite_copy, \
        (sfVector2f) {1900, 0});
    }
    sfRenderWindow_drawSprite(runner->window, \
    runner->parralax_two->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window, \
    runner->parralax_two->sprite_copy, NULL);
}

void parralax_all(runner_t *runner)
{
    runner->parralax_one->position.x -= 8;
    sfSprite_move(runner->parralax_one->sprite, (sfVector2f) {-8, 0});
    sfSprite_move(runner->parralax_one->sprite_copy, (sfVector2f) {-8, 0});
    runner->parralax_two->position.x -= 10;
    sfSprite_move(runner->parralax_two->sprite, (sfVector2f) {-10, 0});
    sfSprite_move(runner->parralax_two->sprite_copy, (sfVector2f) {-10, 0});
}
