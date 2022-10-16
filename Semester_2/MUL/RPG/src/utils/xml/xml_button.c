/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** xml_button
*/

#include "utils/xml.h"

static void xml_button_parser_next(button *button, char *param, char *value)
{
    if (my_str_is_equal(param, "y"))
        button->position = (sfVector2f) {button->position.x,
        my_getnbr(value)};
    if (my_str_is_equal(param, "callback"))
        button->callback = callback_from_name(value).value;
    if (my_str_is_equal(param, "args"))
        button->args = my_str_to_wordarray(value, ' ');
    free(param);
}

button *xml_button_parser(char **content)
{
    button *button = button_create_empty();
    while ((*(*content)) != '>') {
        if (!is_alpha(content))
            continue;
        char *param = xml_get_param(content);
        char *value = xml_get_value(content);
        my_str_is_equal(param, "name") ? button->name = my_strcpy(value) : 0;
        if (my_str_is_equal(param, "image"))
            button->sprite = constructor_sprite_button(button, value);
        if (my_str_is_equal(param, "x"))
            button->position = (sfVector2f) {my_getnbr(value),
            button->position.y};
        xml_button_parser_next(button, param, value);
        free(value);
    }
    int width = sfSprite_getTextureRect(button->sprite).width;
    int height = sfSprite_getTextureRect(button->sprite).height;
    button->size = (sfVector2u) {width, height};
    sfSprite_setPosition(button->sprite, button->position);
    return (button);
}
