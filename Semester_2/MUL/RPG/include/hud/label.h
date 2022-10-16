/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-tom.pierron
** File description:
** text
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include "csfml.h"

typedef struct label {
    sfVector2f position;
    int size;
    char *name;
    sfText *text;
    sfFont *font;
} label;

label *label_create_empty(void);
void label_set_color(label *label, sfColor color);
void label_destroy(label *label);
void label_set_text(label *label, char const *text);
label *label_get_from_name(char const *str);
label *label_create(char const *text, char const *font, int size,
sfVector2f position);

#endif/* !TEXT_H_ */
