/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** runner_utils
*/

#include "../include/my.h"
#include "../include/myrunner.h"

spritesheet_t *image_creator(char *filename, sfVector2f position,
sfIntRect *rectangle, imageType_t type)
{
    spritesheet_t *image = malloc(sizeof(spritesheet_t));
    if (!image)
        return (NULL);
    image->sprite = sfSprite_create();
    image->texture = sfTexture_createFromFile(filename, rectangle);
    image->position = position;
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setPosition(image->sprite, image->position);
    if (rectangle)
        image->rect = *rectangle;
    image->type = type;
    image->jumped = 0;
    image->slide_time = 0;
    image->sprite_copy = sfSprite_copy(image->sprite);
    return (image);
}

int clicked_button(spritesheet_t *image, int x, int y)
{
    sfVector2u size = sfTexture_getSize(image->texture);
    if (x >= image->position.x && x <= image->position.x + size.x) {
        if (y >= image->position.y && y <= image->position.y + size.y) {
            return (1);
        }
    }
    return (0);
}
