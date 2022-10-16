/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** arrow
*/

#ifndef ARROW_H_
    #define ARROW_H_

    #include "csfml.h"
    #include "game/game_obj.h"

typedef struct arrow_s {
    game_obj *obj;
    sfVector2f dest;
    sfVector2f init_pos;
    float speed;
    float damage;
    sfVector2f direction;
} arrow_t;

void arrow_launch(void);
void generate_particules(sfVector2f position);
arrow_t *arrow_create(sfVector2f position, sfVector2f direction);

#endif
