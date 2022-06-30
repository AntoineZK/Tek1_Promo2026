/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_menu
*/

#include "../include/my.h"
#include "../include/myrunner.h"

void win_scene(runner_t *runner)
{
    runner->win_back = image_creator("assets/back_win.jpg",
    (sfVector2f) {0, 0}, NULL, IMAGE);
    runner->quit = image_creator("assets/quit.png", \
    (sfVector2f) {(1900/2 - 100), 600}, NULL, IMAGE);
}

void lose_scene(runner_t *runner)
{
    runner->lose_back = image_creator("assets/back_lose.jpg",
    (sfVector2f) {0, 0}, NULL, IMAGE);
    runner->quit = image_creator("assets/quit.png", \
    (sfVector2f) {(1900/2 - 100), 800}, NULL, IMAGE);
}
