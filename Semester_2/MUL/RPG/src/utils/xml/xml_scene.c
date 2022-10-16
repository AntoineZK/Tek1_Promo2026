/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** xml_scene
*/

#include "utils/xml.h"

static scene *xml_scene_parser_next(scene *scene, char **content)
{
    for (; (*(*content)) == ' '; (*content)++);
    while ((*(*content)) != '\0') {
        (*content)++;
        char *type = xml_get_param(content);
        my_str_is_equal(type, "Game_Object") ?
        scene_add_game_obj(scene, xml_game_obj_parser(content)) : 0;
        my_str_is_equal(type, "Button") ?
        scene_add_button(scene, xml_button_parser(content)) : 0;
        my_str_is_equal(type, "Label") ?
        scene_add_label(scene, xml_label_parser(content)) : 0;
        free(type);
    }
    return (scene);
}

scene *xml_scene_parser(char **content)
{
    scene *scene = scene_create_empty();
    while ((*(*content)) != '>') {
        char *param = xml_get_param(content);
        char *value = xml_get_value(content);
        if (my_str_is_equal(param, "name"))
            scene->name = my_strcpy(value);
        if (my_str_is_equal(param, "background"))
            scene->background = constructor_sprite_scene(scene, value);
        if (my_str_is_equal(param, "z-index")) {
            scene->z_index = my_getnbr(value);
        }
        if (my_str_is_equal(param, "show"))
            scene->selected = my_getnbr(value);
        free(param);
        free(value);
    }
    (*content) += 2;
    return (xml_scene_parser_next(scene, content));
}
