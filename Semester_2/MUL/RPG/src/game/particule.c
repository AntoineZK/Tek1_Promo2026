/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** particule
*/

#include "game/particule.h"
#include "rpg.h"

int check_particules_alive(void)
{
    for (int i = 0; i < 20; ++i) {
        if (rpg->particules[i]->color.a != 0)
            return (1);
    }
    return (0);
}

particule_t *particule_create(sfColor color, shape_type_t type)
{
    particule_t *particule = malloc(sizeof(particule_t));
    particule->position = (sfVector2f) {rand() % 1920, rand() % 1080};
    particule->speed = (sfVector2f) {rand() % 10 - 5, rand() % 10 - 5};
    particule->color = color;
    particule->size = ((rand() % 8) + 3);
    particule->shape = NULL;
    particule->type = type;
    particule->freeze = 0;
    if (type == CIRCLE) {
        particule->shape = (sfShape *) sfCircleShape_create();
        sfCircleShape_setRadius((sfCircleShape *) particule->shape,
        particule->size);
    } else if (type == RECTANGLE) {
        particule->shape = (sfShape *) sfRectangleShape_create();
        sfRectangleShape_setSize((sfRectangleShape *) particule->shape,
        (sfVector2f) {particule->size * 2, particule->size * 2});
    } else if (type == CONVEX)
        particule->shape = (sfShape *) sfConvexShape_create();
    sfShape_setPosition(particule->shape, particule->position);
    return (particule);
}

void particule_destroy(particule_t *particule)
{
    if (particule->type == CIRCLE)
        sfCircleShape_destroy((sfCircleShape *) particule->shape);
    else if (particule->type == RECTANGLE)
        sfRectangleShape_destroy((sfRectangleShape *) particule->shape);
    else if (particule->type == CONVEX)
        sfConvexShape_destroy((sfConvexShape *) particule->shape);
    else
        sfShape_destroy(particule->shape);
    free(particule);
}

void particule_launch(void)
{
    for (int i = 0; i < 20; ++i) {
        if (!rpg->particules[i]->freeze) {
            rpg->particules[i]->position.x += rpg->particules[i]->speed.x;
            rpg->particules[i]->position.y += rpg->particules[i]->speed.y;
            sfShape_setPosition(rpg->particules[i]->shape,
            rpg->particules[i]->position);
        }
        sfShape_setFillColor(rpg->particules[i]->shape,
        rpg->particules[i]->color);
        sfRenderWindow_drawShape(rpg->window,
        rpg->particules[i]->shape, NULL);
    }
}
