/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** particule
*/

#ifndef PARTICULE_H_
    #define PARTICULE_H_

    #include "csfml.h"

typedef enum shape_type_e {
    BASE,
    CIRCLE,
    RECTANGLE,
    CONVEX,
} shape_type_t;

typedef struct particule_s {
    int size;
    sfVector2f position;
    sfVector2f speed;
    sfColor color;
    sfShape *shape;
    shape_type_t type;
    int freeze;
} particule_t;

void particule_launch(void);
particule_t *particule_create(sfColor color, shape_type_t type);
void particule_destroy(particule_t *particule);
int check_particules_alive(void);

#endif/* !PARTICULE_H_ */
