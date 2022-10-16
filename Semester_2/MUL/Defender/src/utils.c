/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCY-1-1-mydefender-antoine.khalidy
** File description:
** defender_utils
*/

#include "../include/defender.h"

image_t *image_create(const char *file, sfVector2f pos)
{
    image_t *image = malloc(sizeof(image_t));
    image->sprite = sfSprite_create();
    image->pos = pos;
    image->texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setPosition(image->sprite, image->pos);
    return (image);
}

int click_btton(image_t *image, int x, int y)
{
    sfVector2u size = (sfVector2u) {0, 0};
    size = sfTexture_getSize(image->texture);
    if (x >= image->pos.x && x <= image->pos.x + size.x) {
        if (y >= image->pos.y && y <= image->pos.y + size.y) {
            return (1);
        }
    }
    return (0);
}

void draw_sprite(defender_t *def, image_t *image)
{
    sfRenderWindow_drawSprite(def->wdw, image->sprite, NULL);
}

void sfDestroy(image_t *image)
{
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
}
