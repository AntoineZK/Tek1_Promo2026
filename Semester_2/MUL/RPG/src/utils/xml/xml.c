/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** xml_parser
*/

#include "utils/xml.h"

scene *xml_parse(char const *filename)
{
    scene *scene = NULL;
    char *content = my_open_file(filename);
    char *ptr = content;
    for (; *content != '\0'; (*content)++) {
        if ((*content) == '<') {
            content++;
            char *type = xml_get_param(&(content));
            my_str_is_equal(type, "Scene") ? scene =
            xml_scene_parser(&content) : 0;
            free(type);
            break;
        }
    }
    free(ptr);
    return (scene);
}
