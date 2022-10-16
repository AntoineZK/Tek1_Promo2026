/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "my.h"

typedef struct mob_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfClock *clock_monster;
    sfTime time_mobs;
    float seconds_monster;
    float speed;
    float speed_max;
    int life;
    int armor;
    int checkp;
    struct mob_s *next;
} mob_t;

typedef struct tower_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfClock *clock_tower;
    sfTime time_tower;
    float sec_tower;
    float damage;
    float atksp;
    float cd;
    int range;
    int effect;
    int tow_id;
    struct tower_s *next;
} tower_t;

typedef enum typetower_s {
    FIRE,
    STONE,
    SLOW,
    MOULA,
    OBE,
    REDMOON,
    FIRE2,
    STONE2,
    SLOW2,
    MOULA2,
    OBE2,
    REDMOON2,
    FIRE3,
    STONE3,
    SLOW3,
    MOULA3,
    OBE3,
    REDMOON3,
} typetower_t;

#endif
