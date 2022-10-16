/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** game_obj
*/

#ifndef GAME_OBJ_H_
    #define GAME_OBJ_H_

    #include "csfml.h"

typedef struct game_obj {
    sfSprite *sprite;
    sfVector2f position;
    sfVector2u size;
    char *name;
    int display;
    sfTexture *texture;
} game_obj;

game_obj *game_obj_create_empty(void);
void game_obj_destroy(game_obj *game_obj);
game_obj *game_obj_create(char const *texture_name, sfVector2f position,
char *name);
void game_obj_set_rect(game_obj *game_obj, sfIntRect rect);
void game_obj_set_position(game_obj *game_obj, int x, int y);
void game_obj_move(game_obj *game_obj, int x, int y);
void game_obj_set_scale(game_obj *game_obj, sfVector2f scale);

#endif/* !GAME_OBJ_H_ */
