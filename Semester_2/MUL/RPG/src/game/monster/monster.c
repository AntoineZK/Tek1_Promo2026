/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** monster
*/

#include "rpg.h"

void set_pos_monster(monster_t *mstr)
{
    for (int i = 0; i <= 7; ++i) {
        sfSprite_setPosition(mstr->obj[i]->sprite, mstr->pos);
    }
}

game_obj *monster_create(char *file, sfVector2f pos, sfIntRect rect)
{
    game_obj *obj = malloc(sizeof(struct game_obj));
    obj->name = NULL;
    obj->position = pos;
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, pos);
    sfSprite_setTextureRect(obj->sprite, rect);
    return (obj);
}

void monster_destroy(monster_t *monster)
{
    for (int i = 0; i <= 7; ++i) {
        game_obj_destroy(monster->obj[i]);
    }
    free(monster);
}

monster_t *create_monster(sfVector2f pos, int type_monster)
{
    monster_t *mstr = malloc(sizeof(monster_t));

    mstr = my_memset(mstr, 0, sizeof(monster_t));
    if (type_monster == SKELETON)
        mstr = type_skeleton(mstr, pos);
    if (type_monster == BOSS)
        mstr = type_boss(mstr, pos);

    return (mstr);
}

void monster_normal(monster_t *mstr, int i)
{
    if (mstr->is_moving == i && !mstr->is_attacking) {
        monster_animation(mstr, i);
    } else if (mstr->is_moving == i && mstr->is_attacking) {
        monster_animation(mstr, i + 4);
    }
}

void monster_draw(monster_t *mstr)
{
    for (int i = 0; i <= 3; ++i) {
        monster_normal(mstr, i);
    }
}
