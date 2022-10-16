/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** keyboard
*/

#ifndef KEYBOARD_H_
    #define KEYBOARD_H_

    #include "csfml.h"

typedef struct touch_s {
    sfKeyCode const key;
    char const *name;
} touch_t;

char const *get_keyname(sfKeyCode key);

#endif/* !KEYBOARD_H_ */
