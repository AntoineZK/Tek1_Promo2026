/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** next
*/

#include "tetris.h"

static char *next_f_line(void)
{
    char *line = malloc(sizeof(char) * 2);
    int i = 1;

    line[0] = '+';
    line[1] = 0;
    for (; i <= 16; i++)
        my_strcat(&line, "-");
    my_strcat(&line, "+");
    my_strcat(&line, "\n");
    return (line);
}

static char *next_l_line(void)
{
    char *line = malloc(sizeof(char) * 2);
    int i = 1;

    line[0] = '+';
    line[1] = 0;
    for (; i <= 16; i++)
        my_strcat(&line, "-");
    my_strcat(&line, "+");
    my_strcat(&line, "\n");
    return (line);
}

void full_next(tetris_t *g)
{
    char *next = next_f_line();
    char *temp =  next_l_line();

    for (int y = 0; y <= 10; y++) {
        my_strcat(&next, "|");
        for (int x = 0; x <= 15; x++) {
            my_strcat(&next, " ");
        }
        my_strcat(&next, "|");
        my_strcat(&next, "\n");
    }
    my_strcat(&next, temp);
    g->next = my_str_to_word_array(next);
    free(temp);
    free(next);
}

void print_next(tetris_t *g)
{
    lk_list *back = g->piece;

    for (int i = 0; g->next[i]; i++) {
        move(g->y_center + i, g->term_col / 2 + g->nb_col + 10);
        printw("%s\n", g->next[i]);
    }
    g->piece->next != NULL ? g->piece = g->piece->next: 0;
    if (g->piece->tetrimino == NULL) {
        g->piece = g->piece->next;
        print_next(g);
    }
    attron(COLOR_PAIR(g->piece->color));
    for (int y = 0; g->piece->tetrimino[y]; y++) {
        for (int x = 0; g->piece->tetrimino[y][x]; x++) {
            move(g->y_center + y + 1, g->term_col / 2 + g->nb_col + 11 + x);
            g->piece->tetrimino[y][x] != ' ' ?
            printw("%c", g->piece->tetrimino[y][x]) : 0;
        }
    }
    attroff(COLOR_PAIR(g->piece->color));
    g->piece = back;
}
