/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_animation
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void animation_ichigo_run(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 100;
    if (rect.left == 600)
        rect.left = 0;
    rect.height = 90;
    rect.width = 100;
    sfSprite_setTextureRect(sprite, rect);
}

runner_t *animation_ichigo_jump(sfSprite *sprite, runner_t *runner)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    if (runner->jump == 1) {
        rect.top = 0;
        rect.left += 115;
        if (rect.left == 690)
            rect.left = 0;
        rect.height = 140;
        rect.width = 120;
        sfSprite_setTextureRect(sprite, rect);
        runner->nb_sprite++;
        if (runner->nb_sprite == 6) {
            runner->jump = 0;
            runner->nb_sprite = 0;
        }
    }
    return (runner);
}

void animation_toshiro_run(sfSprite *sprite)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = 0;
    rect.left += 100;
    if (rect.left >= 600)
        rect.left = 0;
    rect.height = 80;
    rect.width = 100;
    sfSprite_setTextureRect(sprite, rect);
}

runner_t *animation_toshiro_jump(sfSprite *sprite, runner_t *runner)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    if (runner->jump == 1) {
        rect.top = 0;
        rect.left += 100;
        if (rect.left == 600)
            rect.left = 0;
        rect.height = 144;
        rect.width = 100;
        sfSprite_setTextureRect(sprite, rect);
        runner->nb_sprite++;
        if (runner->nb_sprite == 6) {
            runner->jump = 0;
            runner->nb_sprite = 0;
        }
    }
    return (runner);
}
