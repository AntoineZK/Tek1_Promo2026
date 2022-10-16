/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** label_utils
*/

#include "hud/label.h"
#include "rpg.h"

static label* iterate_labels(scene *scene, char const *str)
{
    for (int j = 0; scene->labels[j]; ++j) {
        if (my_str_is_equal(scene->labels[j]->name, str))
            return (scene->labels[j]);
    }
    return (NULL);
}

label *label_get_from_name(char const *str)
{
    label *label = NULL;
    for (int i = 0; rpg->scenes[i]; ++i) {
        label = iterate_labels(rpg->scenes[i], str);
        if (label)
            return (label);
    }
    return (NULL);
}
