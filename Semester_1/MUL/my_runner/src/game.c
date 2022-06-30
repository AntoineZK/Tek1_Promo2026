/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_game
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void game_ichigo(runner_t *runner, linked_list *game)
{
    parralax_nbone(runner);
    parralax_nbtwo(runner);
    while (game) {
        game->value->position.x -= 9;
        sfSprite_setPosition(game->value->sprite, game->value->position);
        sfRenderWindow_drawSprite(runner->window, game->value->sprite, NULL);
        game = game->next;
    }
    parralax_all(runner);
}

void game_toshiro(runner_t *runner, linked_list *game)
{
    parralax_nbone(runner);
    parralax_nbtwo(runner);
    while (game) {
        game->value->position.x -= 9;
        sfSprite_setPosition(game->value->sprite, game->value->position);
        sfRenderWindow_drawSprite(runner->window, game->value->sprite, NULL);
        game = game->next;
    }
    parralax_all(runner);
}
