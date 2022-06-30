/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** highscore_text
*/

#include "../include/myhunter.h"
#include "../include/my.h"

int highscore_get(hunter_t *hunter)
{
    FILE *file_d = fopen("score/highscore", "a+");
    char *buffer = NULL;
    size_t size_buffer = 0;
    if (file_d == NULL)
        return (-1);
    while (getline(&buffer, &size_buffer, file_d) != -1);
    if (buffer != NULL)
        hunter->highscore = my_getnbr(buffer);
    free(buffer);
    fclose(file_d);
    return (0);
}

int highscore_set(hunter_t *hunter)
{
    int file_d = open("score/highscore", O_TRUNC | O_WRONLY);
    if (file_d == -1)
        return (-1);
    write(file_d, int_to_char(hunter->highscore), \
    my_int_len(hunter->highscore) - 1);
    close(file_d);
    return (0);
}

void display_text(hunter_t *hunter, char *line, sfVector2f position, int i)
{
    text_t *text = malloc(sizeof(text_t));
    if (i == 1)
        text->color = sfColor_fromRGB(255, 140, 0);
    else
        text->color = sfColor_fromRGB(255, 50, 0);
    text->txt = sfText_create();
    text->font = sfFont_createFromFile("assets/botw.otf");
    sfText_setString(text->txt, line);
    sfText_setFont(text->txt, text->font);
    sfText_setPosition(text->txt, position);
    sfText_setCharacterSize(text->txt, 50);
    sfText_setColor(text->txt, text->color);
    sfRenderWindow_drawText(hunter->window, text->txt, NULL);
    free(text);
}

void score_text(hunter_t *hunter)
{
    display_text(hunter, "SCORE :", (sfVector2f) {30, 920}, 1);
    display_text(hunter, int_to_char(hunter->score), \
    (sfVector2f) {180, 920}, 1);
    display_text(hunter, "HIGHSCORE :", (sfVector2f) {300, 920}, 1);
    display_text(hunter, int_to_char(hunter->highscore), \
    (sfVector2f) {550, 920}, 1);
    display_text(hunter, "LIFE :", (sfVector2f) {675, 920}, 1);
    display_text(hunter, int_to_char(hunter->nb_life), \
    (sfVector2f) {790, 920}, 1);
}

void menu_text(hunter_t *hunter, int i)
{
    if (i == 1) {
        display_text(hunter ,"THE LEGEND OF ZELDA : PROTECT HYRULE CASTLE", \
        (sfVector2f) {450, 130}, 2);
    } else {
        display_text(hunter ,"DIFFICULTY", \
        (sfVector2f) {830, 100}, 2);
    }
}
