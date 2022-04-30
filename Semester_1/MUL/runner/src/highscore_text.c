/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** highscore
*/

#include "../include/myrunner.h"
#include "../include/my.h"

int highscore_get(runner_t *runner)
{
    FILE *file_d = fopen("score/highscore", "a+");
    char *buffer = NULL;
    size_t size_buffer = 0;
    if (file_d == NULL)
        return (-1);
    while (getline(&buffer, &size_buffer, file_d) != -1);
    if (buffer != NULL)
        runner->highscore = my_getnbr(buffer);
    free(buffer);
    fclose(file_d);
    return (0);
}

int highscore_set(runner_t *runner)
{
    int file_d = open("score/highscore", O_TRUNC | O_WRONLY);
    if (file_d == -1)
        return (-1);
    write(file_d, int_to_char(runner->highscore), \
    my_int_len(runner->highscore) - 1);
    close(file_d);
    return (0);
}

void display_text(runner_t *runner, char *line, sfVector2f position)
{
    text_t *text = malloc(sizeof(text_t));
    text->color = sfColor_fromRGB(255, 140, 0);
    text->txt = sfText_create();
    text->font = sfFont_createFromFile("assets/botw.otf");
    sfText_setString(text->txt, line);
    sfText_setFont(text->txt, text->font);
    sfText_setPosition(text->txt, position);
    sfText_setCharacterSize(text->txt, 50);
    sfText_setColor(text->txt, text->color);
    sfRenderWindow_drawText(runner->window, text->txt, NULL);
    free(text);
}

void score_text(runner_t *runner)
{
    display_text(runner, "SCORE :", (sfVector2f) {50, 30});
    display_text(runner, int_to_char(runner->score), \
    (sfVector2f) {200, 30});
    runner->score += 1;
    display_text(runner, "HIGHSCORE :", (sfVector2f) {50, 80});
    display_text(runner, int_to_char(runner->highscore), \
    (sfVector2f) {300, 80});
}
