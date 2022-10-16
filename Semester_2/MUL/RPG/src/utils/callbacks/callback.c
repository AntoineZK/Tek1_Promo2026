/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** callbacks
*/

#include "utils/callback.h"

func_dict callbacks[12] = {
    {"load_scene", load_scene},
    {"unload_scene", unload_scene},
    {"exit", exit_scene},
    {"load_game", load_game},
    {"set_key", set_key},
    {"increase_volume", increase_volume},
    {"decrease_volume", decrease_volume},
    {"increase_resolution", increase_resolution},
    {"decrease_resolution", decrease_resolution},
    {"validate_resolution", validate_resolution},
    {NULL, NULL}
};

func_dict callback_from_name(char const *name)
{
    for (int i = 0; callbacks[i].key; ++i) {
        if (my_str_is_equal(callbacks[i].key, name))
            return (callbacks[i]);
    }
    return ((func_dict) {"", NULL});
}

scene *get_scene(char const *name)
{
    for (int i = 0; rpg->scenes[i]; ++i) {
        if (my_str_is_equal(rpg->scenes[i]->name, name))
            return (rpg->scenes[i]);
    }
    return (NULL);
}
