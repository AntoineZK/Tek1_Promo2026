/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** scene_obj
*/

#include "hud/scene.h"

scene *scene_create_empty(void)
{
    scene *scene = malloc(sizeof(struct scene));
    scene->background = NULL;
    scene->buttons = malloc(sizeof(button *));
    scene->buttons[0] = NULL;
    scene->game_objs = malloc(sizeof(game_obj *));
    scene->game_objs[0] = NULL;
    scene->music = NULL;
    scene->name = NULL;
    scene->labels = malloc(sizeof(label *));
    scene->labels[0] = NULL;
    scene->selected = sfFalse;
    scene->texture = NULL;
    scene->z_index = 0;
    return (scene);
}

void scene_draw(sfRenderWindow *window, scene *scene)
{
    DRAW_SPRITE(window, scene->background);
    for (int i = 0; scene->game_objs[i]; ++i) {
        DRAW_SPRITE(window, scene->game_objs[i]->sprite);
    }
    for (int i = 0; scene->buttons[i]; ++i)
        DRAW_SPRITE(window, scene->buttons[i]->sprite);
    for (int i = 0; scene->labels[i]; ++i)
        sfRenderWindow_drawText(window, scene->labels[i]->text, NULL);
}

void scene_destroy(scene *scene)
{
    sfTexture_destroy(scene->texture);
    sfSprite_destroy(scene->background);
    free(scene->name);
    sfMusic_destroy(scene->music);
    for (int i = 0; scene->buttons[i]; ++i)
        button_destroy(scene->buttons[i]);
    free(scene->buttons);
    for (int i = 0; scene->labels[i]; ++i)
        label_destroy(scene->labels[i]);
    for (int i = 0; scene->game_objs[i]; ++i)
        game_obj_destroy(scene->game_objs[i]);
    free(scene->game_objs);
    free(scene->labels);
    free(scene);
}
