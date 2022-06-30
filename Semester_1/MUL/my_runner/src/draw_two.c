/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_draw
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void win_draw(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window,
    runner->win_back->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->quit->sprite, NULL);
    display_text(runner, "VICTORY", (sfVector2f) {(1920/2 - 105), 230});
    display_text(runner, "YOUR SCORE :", (sfVector2f) {50, 30});
    display_text(runner, int_to_char(runner->score),
    (sfVector2f) {320, 30});
    display_text(runner, "HIGHSCORE :", (sfVector2f) {50, 80});
    display_text(runner, int_to_char(runner->highscore),
    (sfVector2f) {300, 80});
}

void lose_draw(runner_t *runner)
{
    sfRenderWindow_drawSprite(runner->window,
    runner->lose_back->sprite, NULL);
    sfRenderWindow_drawSprite(runner->window,
    runner->quit->sprite, NULL);
    display_text(runner, "DEFEAT", (sfVector2f) {(1920/2 - 90), 300});
    display_text(runner, "YOUR SCORE :", (sfVector2f) {50, 30});
    display_text(runner, int_to_char(runner->score),
    (sfVector2f) {320, 30});
    display_text(runner, "HIGHSCORE :", (sfVector2f) {50, 80});
    display_text(runner, int_to_char(runner->highscore),
    (sfVector2f) {300, 80});
}
