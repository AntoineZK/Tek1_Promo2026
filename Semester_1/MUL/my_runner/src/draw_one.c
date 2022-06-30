/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_draw
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void menu_draw(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window,
    runner->menu_bg->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->menu_start->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->menu_exit->sprite, NULL);
}

void character_menu_draw(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window,
    runner->character_bg->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->character_home->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->character_ichigo->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->character_toshiro->sprite, NULL);
}

void game_draw_ichigo(runner_t *runner, linked_list *game)
{
    sfRenderWindow_drawSprite(runner->window,
    runner->game_background1->sprite, NULL);
    game_ichigo(runner, game);
    if (runner->jump == 1) {
        runner->ichigo_run->position.y -= 15;
        runner->ichigo_jump->position.y -= 15;
    }
    sfSprite_setPosition(runner->ichigo_run->sprite,
    runner->ichigo_run->position);
    sfSprite_setPosition(runner->ichigo_jump->sprite,
    runner->ichigo_jump->position);
    ichigo_animation(runner, game);
    score_text(runner);
}

void game_draw_toshiro(runner_t *runner, linked_list *game)
{
    sfRenderWindow_drawSprite(runner->window,
    runner->game_background1->sprite, NULL);
    game_toshiro(runner, game);
    if (runner->jump == 1) {
        runner->toshiro_run->position.y -= 15;
        runner->toshiro_jump->position.y -= 15;
    }
    sfSprite_setPosition(runner->toshiro_run->sprite,
    runner->toshiro_run->position);
    sfSprite_setPosition(runner->toshiro_jump->sprite,
    runner->toshiro_jump->position);
    toshiro_animation(runner, game);
    score_text(runner);
}
