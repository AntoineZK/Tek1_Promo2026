/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** xml_label
*/

#include "utils/xml.h"

static void xml_label_parser_next(label *label, char *param, char *value)
{
    if (my_str_is_equal(param, "size"))
        label->size = my_getnbr(value);
    if (my_str_is_equal(param, "color"))
        label_set_color(label, constructor_rgba(value));
    if (my_str_is_equal(param, "x"))
        label->position = (sfVector2f) {my_getnbr(value),
        label->position.y};
    if (my_str_is_equal(param, "y"))
        label->position = (sfVector2f) {label->position.x,
        my_getnbr(value)};
    if (my_str_is_equal(param, "font"))
        label->font = sfFont_createFromFile(value);
}

label *xml_label_parser(char **content)
{
    label *label = label_create_empty();
    while ((*(*content)) != '>') {
        if (!is_alpha(content))
            continue;
        char *param = xml_get_param(content);
        char *value = xml_get_value(content);
        if (my_str_is_equal(param, "text"))
            sfText_setString(label->text, value);
        if (my_str_is_equal(param, "name")) {
            free(label->name);
            label->name = my_strcpy(value);
        }
        xml_label_parser_next(label, param, value);
        free(param);
        free(value);
    }
    sfText_setFont(label->text, label->font);
    sfText_setCharacterSize(label->text, label->size);
    sfText_setPosition(label->text, label->position);
    return (label);
}
