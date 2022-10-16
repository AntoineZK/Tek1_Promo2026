/*
** EPITECH PROJECT, 2022
** rpg_alone
** File description:
** text
*/

#include "rpg.h"

void d_text_pol(sfRenderWindow *wdw, char *line, sfVector2f pos, int pol)
{
    text_t *text = malloc(sizeof(text_t));
    text->color = sfWhite;
    text->text = sfText_create();
    text->font = sfFont_createFromFile("assets/font.ttf");
    sfText_setString(text->text, line);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, pos);
    sfText_setCharacterSize(text->text, pol);
    sfText_setColor(text->text, text->color);
    sfRenderWindow_drawText(wdw, text->text, NULL);
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(text);
}

void d_text_col(sfRenderWindow *wdw, char *line, sfVector2f pos, sfColor col)
{
    text_t *text = malloc(sizeof(text_t));
    text->color = col;
    text->text = sfText_create();
    text->font = sfFont_createFromFile("assets/font.ttf");
    sfText_setString(text->text, line);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, pos);
    sfText_setCharacterSize(text->text, 40);
    sfText_setColor(text->text, text->color);
    sfRenderWindow_drawText(wdw, text->text, NULL);
    sfText_destroy(text->text);
    sfFont_destroy(text->font);
    free(text);
}
