/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** monsters
*/

#ifndef MONSTERS_H_
    #define MONSTERS_H_
    #include "csfml.h"
    #include "game/game_obj.h"

enum movement_monster {
    MSTR_DOWN,
    MSTR_UP,
    MSTR_LEFT,
    MSTR_RIGHT,
    MSTR_AT_DOWN,
    MSTR_AT_UP,
    MSTR_AT_LEFT,
    MSTR_AT_RIGHT,
};

enum monster_type {
    SKELETON,
    ZOMBIE,
    BOSS,
};

typedef struct monster_s {
    game_obj **obj;
    int hp;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float sec;
    int speed;
    int damage;
    int xp;
    int is_alive;
    int is_moving;
    int is_attacking;
    int is_hit;
    int is_hiting;
    int len;
    int moving_status;
    int in_range;
    int *status;
    float angle;
    sfVector2f pos;
} monster_t;

void monster_destroy(monster_t *monster);

#endif
