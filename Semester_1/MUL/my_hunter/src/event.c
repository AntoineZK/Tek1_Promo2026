/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** event
*/

#include "../include/my.h"
#include "../include/myhunter.h"

hunter_t *hunter_event(hunter_t *hunter)
{
    if (hunter->event.type == sfEvtKeyPressed) {
        if (hunter->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(hunter->window);
        }
    }
    if (hunter->event.type == sfEvtMouseButtonPressed && (hunter->scene == 2 \
    || hunter->scene == 3 || hunter->scene == 4)) {
        hunter = kill_mobs(hunter);
    } else if (hunter->event.type == sfEvtMouseButtonPressed) {
        hunter = hunter_event_menu(hunter);
    }
    return (hunter);
}

hunter_t *hunter_event_menu(hunter_t *hunter)
{
    if (clicked_button(hunter->exit, hunter->event.mouseButton.x,
    hunter->event.mouseButton.y) &&
    (hunter->scene == 0 || hunter->scene == 5 || hunter->scene == 6))
        sfRenderWindow_close(hunter->window);
    else if (clicked_button(hunter->start, hunter->event.mouseButton.x,
                            hunter->event.mouseButton.y) && hunter->scene == 0)
        hunter->scene = 1;
    else if (clicked_button(hunter->easy, hunter->event.
    mouseButton.x, hunter->event.mouseButton.y) && hunter->scene == 1)
        hunter->scene = 2;
    else if (clicked_button(hunter->normal, hunter->event.
    mouseButton.x, hunter->event.mouseButton.y) && hunter->scene == 1)
        hunter->scene = 3;
    else if (clicked_button(hunter->hard, hunter->event.
    mouseButton.x, hunter->event.mouseButton.y) && hunter->scene == 1)
        hunter->scene = 4;
    else if (clicked_button(hunter->home, hunter->event.
    mouseButton.x, hunter->event.mouseButton.y) && hunter->scene == 1)
        hunter->scene = 0;
    return (hunter);
}
