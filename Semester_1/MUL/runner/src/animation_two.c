/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_jump
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void toshiro_animation(runner_t *runner, linked_list *game)
{
    death_management_toshiro(runner, game);
    runner->time_toshiro = sfClock_getElapsedTime(runner->clock_toshiro);
    runner->sec_toshiro = runner->time_toshiro.microseconds / 1000000.0;
    if (runner->jump == 0) {
        if (runner->sec_toshiro > 0.12) {
            sfClock_restart(runner->clock_toshiro);
            animation_toshiro_run(runner->toshiro_run->sprite);
        }
        sfRenderWindow_drawSprite(runner->window, \
        runner->toshiro_run->sprite, NULL);
    }
    if (runner->jump == 1) {
        if (runner->sec_toshiro > 0.10) {
            sfClock_restart(runner->clock_toshiro);
            animation_toshiro_jump(runner->toshiro_jump->sprite, runner);
        }
        sfRenderWindow_drawSprite(runner->window, \
        runner->toshiro_jump->sprite, NULL);
    }
}

void ichigo_animation(runner_t *runner, linked_list *game)
{
    death_management_ichigo(runner, game);
    runner->time_ichigo = sfClock_getElapsedTime(runner->clock_ichigo);
    runner->sec_ichigo = runner->time_ichigo.microseconds / 1000000.0;
    if (runner->jump == 0) {
        if (runner->sec_ichigo > 0.12) {
            sfClock_restart(runner->clock_ichigo);
            animation_ichigo_run(runner->ichigo_run->sprite);
        }
        sfRenderWindow_drawSprite(runner->window, \
        runner->ichigo_run->sprite, NULL);
    }
    if (runner->jump == 1) {
        if (runner->sec_ichigo > 0.10) {
            sfClock_restart(runner->clock_ichigo);
            animation_ichigo_jump(runner->ichigo_jump->sprite, runner);
        }
        sfRenderWindow_drawSprite(runner->window, \
        runner->ichigo_jump->sprite, NULL);
    }
}
