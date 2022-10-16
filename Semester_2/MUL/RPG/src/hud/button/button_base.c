/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** button_obj
*/

#include "hud/button.h"

button *button_create_empty(void)
{
    button *button = malloc(sizeof(struct button));
    button->callback = NULL;
    button->args = NULL;
    button->disable = 0;
    button->hover = 0;
    button->name = NULL;
    button->position = (sfVector2f) {0};
    button->size = (sfVector2u) {0};
    button->sprite = NULL;
    return (button);
}

button *button_create(char const *texture_name, sfVector2f position,
int (*callback) (char **), char *name)
{
    button *button = malloc(sizeof(struct button));
    sfTexture *texture = sfTexture_createFromFile(texture_name, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, texture, sfTrue);
    int width = sfSprite_getTextureRect(button->sprite).width;
    int height = sfSprite_getTextureRect(button->sprite).height;
    button->size = (sfVector2u) {width, height};
    button->position = position;
    button->callback = callback;
    button->hover = sfFalse;
    button->name = my_strcpy(name);
    return (button);
}

void button_destroy(button *button)
{
    if (button->args) {
        for (int i = 0; button->args[i]; ++i)
            free(button->args[i]);
        free(button->args);
    }
    free(button->name);
    sfTexture_destroy(button->texture);
    sfSprite_destroy(button->sprite);
    free(button);
}
