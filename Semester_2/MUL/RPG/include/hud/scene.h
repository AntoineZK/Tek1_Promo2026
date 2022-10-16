/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** scene
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include "button.h"
    #include "label.h"
    #include <sys/types.h>
    #include <dirent.h>
    #include "game/game_obj.h"

typedef struct scene {
    sfSprite *background;
    game_obj **game_objs;
    label **labels;
    button **buttons;
    sfMusic *music;
    sfTexture *texture;
    char *name;
    sfBool selected;
    int z_index;
} scene;

scene *scene_create_empty(void);
void scene_add_game_obj(scene *scene, game_obj *game_obj);
void scene_add_button(scene *scene, button *button);
void scene_add_label(scene *scene, label *label);
void scene_draw(sfRenderWindow *window, scene *scene);
void scene_destroy(scene *scene);
void scene_load_all(scene **scenes);

#endif/* !SCENE_H_ */
