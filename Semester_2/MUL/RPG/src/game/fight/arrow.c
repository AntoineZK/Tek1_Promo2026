/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** arrow
*/

#include "game/arrow.h"
#include "rpg.h"
#include "math.h"

void generate_particules(sfVector2f position)
{
    for (int i = 0; i < 20; ++i) {
        if (rpg->particules[i]->position.x == -1 &&
        rpg->particules[i]->position.y == -1) {
            rpg->particules[i]->position = position;
            rpg->particules[i]->color.a = 255;
            rpg->particules[i]->freeze = 0;
        } else if (rpg->particules[i]->color.a - 10 > 0)
            rpg->particules[i]->color.a -= 10;
        else {
            rpg->particules[i]->freeze = 1;
            rpg->particules[i]->color.a = 0;
            rpg->particules[i]->position = (sfVector2f) {-1, -1};
        }
    }
}

arrow_t *arrow_create(sfVector2f position, sfVector2f direction)
{
    arrow_t *arrow = malloc(sizeof(arrow_t));
    position.x += sfSprite_getTextureRect(rpg->player->image[0]->sprite).
    width / 2;
    position.y += sfSprite_getTextureRect(rpg->player->image[0]->sprite).
    height / 2;
    arrow->obj = game_obj_create("assets/weapon/arrow.png", position, "arrow");
    game_obj_set_scale(arrow->obj, (sfVector2f){0.25, 0.25});
    arrow->speed = 0.05;
    arrow->damage = 10;
    arrow->init_pos = position;
    arrow->dest = direction;
    double norm = sqrt(pow(direction.y - position.y, 2) +
    pow(direction.x - position.x, 2));
    arrow->direction = (sfVector2f) {(direction.x - position.x)/norm,
    (direction.y - position.y)/norm};
    return (arrow);
}

void arrow_destroy(arrow_t *arrow)
{
    game_obj_destroy(arrow->obj);
    free(arrow);
}

static int check_arrow_finish(void)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->arrow->obj->sprite);
    sfVector2f dest = rpg->player->arrow->dest;

    if (rpg->player->arrow->init_pos.x < dest.x) {
        if (pos.x > dest.x) {
            arrow_destroy(rpg->player->arrow);
            rpg->player->is_able[BOW] = 2;
            return (1);
        }
    } else {
        if (pos.x < rpg->player->arrow->dest.x) {
            arrow_destroy(rpg->player->arrow);
            rpg->player->is_able[BOW] = 2;
            return (1);
        }
    }
    return (0);
}

void arrow_launch(void)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->arrow->obj->sprite);
    sfVector2f dir = rpg->player->arrow->direction;
    sfVector2f speed = {dir.x / rpg->player->arrow->speed, dir.y /
    rpg->player->arrow->speed};
    sfVector2f new_pos = {pos.x + speed.x, pos.y + speed.y};

    if (check_arrow_finish()) {
        rpg->player->arrow_last_pos = new_pos;
        generate_particules(new_pos);
        for (int i = 0; rpg->monsters[i]; ++i) {
            if (rpg->monsters[i]->hp > 0 && in_range(new_pos,
            rpg->monsters[i]->pos, 100)) {
                rpg->monsters[i]->hp -= rpg->player->arrow->damage;
            }
        }
        return;
    }
    sfSprite_setPosition(rpg->player->arrow->obj->sprite, new_pos);
    sfSprite_setRotation(rpg->player->arrow->obj->sprite,
    atan2(dir.y, dir.x) * 180 / M_PI);
    DRAW_SPRITE(rpg->window, rpg->player->arrow->obj->sprite);
}
