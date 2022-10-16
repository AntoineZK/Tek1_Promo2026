/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** scene_utils
*/

#include "hud/scene.h"

scene *xml_parse(char const *filename);

static void sort_scenes(scene **scenes)
{
    for (int i = 1; scenes[i]; ++i) {
        scene *temp = scenes[i];
        int index = i - 1;
        while (index >= 0 && temp->z_index < scenes[index]->z_index) {
            scenes[index + 1] = scenes[index];
            index--;
        }
        scenes[index + 1] = temp;
    }
}

void scene_load_all(scene **scenes)
{
    DIR *scenes_folder = opendir("assets/scenes");
    struct dirent *dir;
    int i = 0;
    char *filename = NULL;
    while ((dir = readdir(scenes_folder))) {
        if (dir->d_name[0] == '.')
            continue;
        filename = malloc(sizeof(char));
        filename[0] = '\0';
        my_strcat_dyn(&filename, "assets/scenes/");
        my_strcat_dyn(&filename, dir->d_name);
        scenes[i] = xml_parse(filename);
        free(filename);
        ++i;
    }
    scenes[i] = NULL;
    sort_scenes(scenes);
    free(scenes_folder);
}

void scene_add_game_obj(scene *scene, game_obj *game_obj)
{
    int len = 0;
    for (; scene->game_objs[len]; len++);
    struct game_obj **game_objs = malloc(sizeof(game_obj) * (len + 2));
    for (int i = 0; scene->game_objs[i]; ++i)
        game_objs[i] = scene->game_objs[i];
    game_objs[len] = game_obj;
    game_objs[len + 1] = NULL;
    free(scene->game_objs);
    scene->game_objs = game_objs;
}

void scene_add_button(scene *scene, button *button)
{
    int len = 0;
    for (; scene->buttons[len]; len++);
    struct button **buttons = malloc(sizeof(button) * (len + 2));
    for (int i = 0; scene->buttons[i]; ++i)
        buttons[i] = scene->buttons[i];
    buttons[len] = button;
    buttons[len + 1] = NULL;
    free(scene->buttons);
    scene->buttons = buttons;
}

void scene_add_label(scene *scene, label *label)
{
    int len = 0;
    for (; scene->labels[len]; len++);
    struct label **labels = malloc(sizeof(label) * (len + 2));
    for (int i = 0; scene->labels[i]; ++i)
        labels[i] = scene->labels[i];
    labels[len] = label;
    labels[len + 1] = NULL;
    free(scene->labels);
    scene->labels = labels;
}
