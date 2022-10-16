/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** map_panel
*/

#include "tetris.h"

static char *first_last_line(tetris_t *g)
{
    char *line = malloc(sizeof(char) * 2);
    int i = 1;

    line[0] = '+';
    line[1] = 0;
    for (; i < g->col + 1; i++) {
        my_strcat(&line, "-");
    }
    my_strcat(&line, "+");
    my_strcat(&line, "\n");
    return (line);
}

void full_map(tetris_t *g)
{
    char *map = first_last_line(g);
    char *temp =  first_last_line(g);

    for (int y = 0; y <= g->line + 2; y++) {
        my_strcat(&map, "|");
        for (int x = 0; x < g->col; x++) {
            my_strcat(&map, " ");
        }
        my_strcat(&map, "|");
        my_strcat(&map, "\n");
    }
    my_strcat(&map, temp);
    free(temp);
    g->map = my_str_to_word_array(map);
    g->nb_col = nb_column(map);
    g->nb_l = nb_line(map);
    free(map);
}

static char *panel_f_line(void)
{
    char *line = malloc(sizeof(char) * 2);
    int i = 1;

    line[0] = '+';
    line[1] = 0;
    for (; i <= 21; i++)
        my_strcat(&line, "-");
    my_strcat(&line, "+");
    my_strcat(&line, "\n");
    return (line);
}

static char *panel_l_line(void)
{
    char *line = malloc(sizeof(char) * 2);
    int i = 1;

    line[0] = '+';
    line[1] = 0;
    for (; i <= 21; i++)
        my_strcat(&line, "-");
    my_strcat(&line, "+");
    my_strcat(&line, "\n");
    return (line);
}

void full_panel(tetris_t *g)
{
    char *panel = panel_f_line();
    char *temp =  panel_l_line();

    for (int y = 0; y <= 22; y++) {
        my_strcat(&panel, "|");
        for (int x = 0; x <= 20; x++) {
            my_strcat(&panel, " ");
        }
        my_strcat(&panel, "|");
        my_strcat(&panel, "\n");
    }
    my_strcat(&panel, temp);
    g->panel = my_str_to_word_array(panel);
    free(temp);
    free(panel);
}
