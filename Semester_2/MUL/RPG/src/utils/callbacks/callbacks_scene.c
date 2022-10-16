/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** callbacks_scene
*/

#include "utils/callback.h"

char *maps[3] = {"map/collision.txt", "map/mob.txt", NULL};

int unload_scene(char **args)
{
    char *scene_name = args[0];
    for (int i = 0; rpg->scenes[i]; ++i) {
        if (my_str_is_equal(rpg->scenes[i]->name, scene_name)) {
            rpg->scenes[i]->selected = sfFalse;
            return (0);
        }
    }
    return (1);
}

int load_scene(char **args)
{
    char *scene_name = args[0];
    for (int i = 0; rpg->scenes[i]; ++i) {
        if (my_str_is_equal(rpg->scenes[i]->name, scene_name)) {
            rpg->scenes[i]->selected = sfTrue;
            return (0);
        }
    }
    return (1);
}

int exit_scene(char **args)
{
    write(1, args[0], 0);
    return (2);
}

static char *load_game_2(char *save_name, char *file_value)
{
    if (my_str_is_equal(save_name, "1")) {
        file_value = my_open_file("save/save1.txt");
        rpg->save_value = 1;
    }
    if (my_str_is_equal(save_name, "2")) {
        file_value = my_open_file("save/save2.txt");
        rpg->save_value = 2;
    }
    if (my_str_is_equal(save_name, "3")) {
        file_value = my_open_file("save/save3.txt");
        rpg->save_value = 3;
    }
    return (file_value);
}

int load_game(char **args)
{
    char *save_name = args[0];
    char *file_value = NULL;

    rpg->c_map = malloc(sizeof(char *) * 3);
    for (int i = 0; maps[i]; ++i)
        rpg->c_map[i] = my_open_file(maps[i]);
    rpg->c_map[2] = NULL;
    rpg->d_map = malloc(sizeof(char **) * 3);
    for (int i = 0; rpg->c_map[i]; ++i)
        rpg->d_map[i] = my_str_to_wordarray(rpg->c_map[i], '\n');
    rpg->d_map[2] = NULL;
    for (int i = 0; rpg->scenes[i]; ++i)
        rpg->scenes[i]->selected = sfFalse;
    file_value = load_game_2(save_name, file_value);
    if (file_value != NULL)
        get_save(file_value);
    free(file_value);
    rpg->in_game = 1;
    sfView_setCenter(rpg->view, rpg->player->pos);
    return (0);
}
