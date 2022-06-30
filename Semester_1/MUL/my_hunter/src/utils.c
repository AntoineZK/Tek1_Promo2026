/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** utils
*/

#include "../include/my.h"
#include "../include/myhunter.h"

spritesheet_t *image_creator(char *filename, sfVector2f position,
sfIntRect *rectangle)
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
