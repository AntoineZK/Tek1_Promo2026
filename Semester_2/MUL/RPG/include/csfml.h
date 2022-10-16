/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** csfml
*/

#ifndef CSFML_H_
    #define CSFML_H_
    #include "my.h"
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <time.h>
    #include <math.h>
    #define DRAW_SPRITE(window, sprite)\
    sfRenderWindow_drawSprite(window, sprite, NULL)
typedef struct text_s {
    sfText *text;
    sfFont *font;
    sfColor color;
} text_t;

#endif
