/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** options
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_

    #include "csfml.h"

typedef enum key_type_e {
    UP_KEY,
    DOWN_KEY,
    LEFT_KEY,
    RIGHT_KEY,
    HIT_KEY,
    ARROW_KEY,
    DASH_KEY,
    INTERACT_KEY,
    PAUSE_KEY,
    INVENTORY_KEY,
    MINIMAP_KEY,
} key_type_t;

typedef struct options_s {
    int *keys;  
    float sound_volume;
    float music_volume;
    int fullscreen;
    unsigned int resolution[2];
    int resolution_index;
} options_t;

options_t *options_create(void);
void options_destroy(options_t *options);

#endif/* !OPTIONS_H_ */
