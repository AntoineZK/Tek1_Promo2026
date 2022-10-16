/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** xml
*/

#ifndef XML_H_
    #define XML_H_

    #include "hud.h"
    #include "utils/constructor.h"
    #include "utils/callback.h"

scene *xml_parse(char const *filename);
char *xml_get_value(char **content);
char *xml_get_param(char **content);
game_obj *xml_game_obj_parser(char **content);
scene *xml_scene_parser(char **content);
button *xml_button_parser(char **content);
label *xml_label_parser(char **content);

#endif/* !XML_H_ */
