/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** draw_two
*/

#include "../include/my.h"
#include "../include/myhunter.h"

void win_draw(hunter_t *hunter)
{
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->win_back->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->exit->sprite, NULL);
    display_text(hunter, "VICTORY", (sfVector2f) {1920/2 - 105, 230}, 1);
    display_text(hunter, "YOUR SCORE :", (sfVector2f) {50, 30}, 1);
    display_text(hunter, int_to_char(hunter->score), \
    (sfVector2f) {320, 30}, 1);
    display_text(hunter, "HIGHSCORE :", (sfVector2f) {50, 80}, 1);
    display_text(hunter, int_to_char(hunter->highscore), \
    (sfVector2f) {300, 80}, 1);
}

void lose_draw(hunter_t *hunter)
{
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->lose_back->sprite, NULL);
    sfRenderWindow_drawSprite(hunter->window, \
    hunter->exit->sprite, NULL);
    display_text(hunter, "YOUR SCORE :", (sfVector2f) {50, 30}, 2);
    display_text(hunter, int_to_char(hunter->score), \
    (sfVector2f) {320, 30}, 2);
    display_text(hunter, "HIGHSCORE :", (sfVector2f) {50, 80}, 2);
    display_text(hunter, int_to_char(hunter->highscore), \
    (sfVector2f) {300, 80}, 2);
}
