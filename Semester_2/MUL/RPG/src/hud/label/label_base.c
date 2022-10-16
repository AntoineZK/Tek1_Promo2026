/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** label_base
*/

#include "hud/label.h"

label *label_create_empty(void)
{
    label *label = malloc(sizeof(struct label));
    label->size = 0;
    label->position = (sfVector2f) {0};
    label->text = sfText_create();
    label->name = malloc(sizeof(char));
    label->name[0] = '\0';
    return (label);
}

label *label_create(char const *text, char const *font, int size,
sfVector2f position)
{
    label *label = malloc(sizeof(struct label));
    label->size = size;
    label->position = position;
    label->text = sfText_create();
    label->name = malloc(sizeof(char));
    label->name[0] = '\0';
    label->font = sfFont_createFromFile(font);
    sfText_setFont(label->text, label->font);
    sfText_setString(label->text, my_strcpy(text));
    sfText_setCharacterSize(label->text, size);
    sfText_setPosition(label->text, label->position);
    return (label);
}

void label_set_text(label *label, char const *text)
{
    char *tmp = my_strcpy(text);
    sfText_setString(label->text, tmp);
    free(tmp);
}

void label_destroy(label *label)
{
    sfFont_destroy(label->font);
    sfText_destroy(label->text);
    free(label->name);
    free(label);
}

void label_set_color(label *label, sfColor color)
{
    sfText_setColor(label->text, color);
}
