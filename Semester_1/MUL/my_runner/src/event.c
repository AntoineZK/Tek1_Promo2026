/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_event
*/

#include "../include/my.h"
#include "../include/myrunner.h"

runner_t *runner_event(runner_t *runner)
{
    if (runner->event.type == sfEvtKeyPressed) {
        if (runner->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(runner->window);
        }
    }
    if (runner->event.type == sfEvtKeyPressed && runner->event.key.code
    == sfKeySpace && runner->anti_jump == 0 && (runner->scene == 2 ||
    runner->scene == 3)) {
        runner->jump = 1;
        runner->anti_jump = 1;
        sfSound_play(runner->sound_jump);
    }
    if (runner->event.type == sfEvtMouseButtonPressed) {
        runner = runner_event_menu(runner);
    }
    return (runner);
}

runner_t *runner_event_menu(runner_t *runner)
{
    if (clicked_button(runner->menu_exit, runner->event.mouseButton.x, \
    runner->event.mouseButton.y) && runner->scene == 0)
        sfRenderWindow_close(runner->window);
    if (clicked_button(runner->quit, runner->event.mouseButton.x, \
    runner->event.mouseButton.y) && (runner->scene == 4 || runner->scene == 5))
        sfRenderWindow_close(runner->window);
    if (clicked_button(runner->menu_start, runner->event.mouseButton.x, \
    runner->event.mouseButton.y) && runner->scene == 0)
        runner->scene = 1;
    if (clicked_button(runner->character_ichigo, runner->event. \
    mouseButton.x, runner->event.mouseButton.y) && runner->scene == 1)
        runner->scene = 2;
    if (clicked_button(runner->character_toshiro, runner->event. \
    mouseButton.x, runner->event.mouseButton.y) && runner->scene == 1)
        runner->scene = 3;
    if (clicked_button(runner->character_home, runner->event. \
    mouseButton.x, runner->event.mouseButton.y) && runner->scene == 1)
        runner->scene = 0;
    return (runner);
}
