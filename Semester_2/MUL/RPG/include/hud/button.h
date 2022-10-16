/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

    #include "csfml.h"

typedef struct button {
    sfSprite *sprite;
    sfBool hover;
    sfBool disable;
    sfVector2f position;
    sfVector2u size;
    int (*callback) (char **);
    sfTexture *texture;
    char **args;
    char *name;
} button;

button *button_create(char const *texture_name, sfVector2f position,
int (*callback) (char **), char *name);
button *button_create_empty(void);
void button_destroy(button *button);
void button_set_position(button *button, int x, int y);
void button_move(button *button, int x, int y);
int button_is_clicked(button *button, int mouse_x, int mouse_y);
void button_is_hover(button *button, int mouse_x, int mouse_y);

#endif/* !BUTTON_H_ */
