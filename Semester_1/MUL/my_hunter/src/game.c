/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** game
*/

#include "../include/my.h"
#include "../include/myhunter.h"

hunter_t *kill_the_goblin(hunter_t *hunter)
{
    sfVector2f detector = sfSprite_getPosition(hunter->goblin->sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
    if (mouse.x >= detector.x && mouse.x <= (detector.x + 150) &&
        mouse.y >= detector.y && mouse.y <= (detector.y + 150)) {
        hunter->score += 1;
        int x = 0;
        sfVector2f my_pos = {x, 720};
        sfSprite_setPosition(hunter->goblin->sprite, my_pos);
    }
    return (hunter);
}

hunter_t *kill_the_wyvern(hunter_t *hunter)
{
    sfVector2f detector = sfSprite_getPosition(hunter->wyvern->sprite);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hunter->window);
    if (mouse.x >= detector.x && mouse.x <= (detector.x + 200) &&
        mouse.y >= detector.y && mouse.y <= (detector.y + 200)) {
        hunter->score += 1;
        int x = 0;
        int y = 0;
        srand(time(NULL));
        y = (rand() % (650));
        sfVector2f my_pos = {x, y};
        sfSprite_setPosition(hunter->wyvern->sprite, my_pos);
    }
    return (hunter);
}

hunter_t *revive_goblin(hunter_t *hunter)
{
    sfVector2f detector = sfSprite_getPosition(hunter->goblin->sprite);
    if (detector.x >= 1900) {
        hunter->nb_life -= 1;
        int x = -100;
        sfVector2f my_pos = {x, 720};
        sfSprite_setPosition(hunter->goblin->sprite, my_pos);
    }
    if (hunter->nb_life <= 0)
        hunter->scene = 5;
    return (hunter);
}

hunter_t *revive_wyvern(hunter_t *hunter)
{
    sfVector2f detector = sfSprite_getPosition(hunter->wyvern->sprite);
    if (detector.x >= 1900) {
        hunter->nb_life -= 1;
        int x = -100;
        int y = 0;
        srand(time(NULL));
        y = (rand() % (650));
        sfVector2f my_pos = {x, y};
        sfSprite_setPosition(hunter->wyvern->sprite, my_pos);
    }
    if (hunter->nb_life <= 0)
        hunter->scene = 5;
    return (hunter);
}
