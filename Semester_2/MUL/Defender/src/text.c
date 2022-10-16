/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** text
*/

#include "../include/defender.h"

void text_game(defender_t *def, map_t *game)
{
    game = print_map(def, game);
    char *int1 = int_to_char(def->mwave);
    char *int2 = int_to_char(def->wave);
    char *int3 = int_to_char(def->money);
    char *int4 = int_to_char(def->life);
    display_text(def, "Max Wave =", (sfVector2f) {1500, 50}, 40);
    display_text(def, int1, (sfVector2f) {1775, 50}, 40);
    display_text(def, "Wave =", (sfVector2f) {1535, 110}, 40);
    display_text(def, int2, (sfVector2f) {1700, 110}, 40);
    display_text(def, int3, (sfVector2f) {1700, 180}, 50);
    display_text(def, int4, (sfVector2f) {1700, 280}, 50);
    free(int1);
    free(int2);
    free(int3);
    free(int4);
}

void d_price(defender_t *def, char *line, sfVector2f pos, sfColor color)
{
    text_t *text = malloc(sizeof(text_t));
    text->color = color;
    text->txt = sfText_create();
    text->font = sfFont_createFromFile("res/font.ttf");
    sfText_setString(text->txt, line);
    sfText_setFont(text->txt, text->font);
    sfText_setPosition(text->txt, pos);
    sfText_setCharacterSize(text->txt, 30);
    sfText_setColor(text->txt, text->color);
    sfRenderWindow_drawText(def->wdw, text->txt, NULL);
    sfText_destroy(text->txt);
    sfFont_destroy(text->font);
    free(text);
}

void price_tower_two(defender_t *def)
{
    if (def->money < def->price_tow[REDMOON])
        d_price(def, "REDMOON: 800", (sfVector2f) {1720, 1030}, sfRed);
    else
        d_price(def, "REDMOON: 800", (sfVector2f) {1720, 1030}, sfWhite);
    if (def->money < def->price_tow[OBE])
        d_price(def, "OBE: 500", (sfVector2f) {1730, 800}, sfRed);
    else
        d_price(def, "OBE: 500", (sfVector2f) {1730, 800}, sfWhite);
}

void price_tower_one(defender_t *def)
{
    if (def->money < def->price_tow[FIRE])
        d_price(def, "FIRE: 100", (sfVector2f) {1415, 800}, sfRed);
    else
        d_price(def, "FIRE: 100", (sfVector2f) {1415, 800}, sfWhite);
    if (def->money < def->price_tow[STONE])
        d_price(def, "STONE: 200", (sfVector2f) {1570, 800}, sfRed);
    else
        d_price(def, "STONE: 200", (sfVector2f) {1570, 800}, sfWhite);
    if (def->money < def->price_tow[SLOW])
        d_price(def, "SLOW: 150", (sfVector2f) {1580, 1030}, sfRed);
    else
        d_price(def, "SLOW: 150", (sfVector2f) {1580, 1030}, sfWhite);
    if (def->money < def->price_tow[MOULA])
        d_price(def, "MOULA: 300", (sfVector2f) {1415, 1030}, sfRed);
    else
        d_price(def, "MOULA: 300", (sfVector2f) {1415, 1030}, sfWhite);
    price_tower_two(def);
}

void display_text(defender_t *def, char *line, sfVector2f pos, int pol)
{
    text_t *text = malloc(sizeof(text_t));
    text->color = sfWhite;
    text->txt = sfText_create();
    text->font = sfFont_createFromFile("res/font.ttf");
    sfText_setString(text->txt, line);
    sfText_setFont(text->txt, text->font);
    sfText_setPosition(text->txt, pos);
    sfText_setCharacterSize(text->txt, pol);
    sfText_setColor(text->txt, text->color);
    sfRenderWindow_drawText(def->wdw, text->txt, NULL);
    sfText_destroy(text->txt);
    sfFont_destroy(text->font);
    free(text);
}
