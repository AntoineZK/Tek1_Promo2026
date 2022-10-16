/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** information
*/

#include "tetris.h"

void print_info(tetris_t *g, int time)
{
    g->seconds = time % 60;
    g->minutes = time / 60;
    move(g->y_center + 3, g->term_col / 3 - 8);
    printw("Highscore : %d", g->highscore);
    move(g->y_center + 7, g->term_col / 3 - 8);
    printw("Score : %d", g->score);
    move(g->y_center + 11, g->term_col / 3 - 8);
    printw("Deleted line : %d", g->del_line);
    move(g->y_center + 17, g->term_col / 3 - 8);
    printw("Level : %d", g->level);
    move(g->y_center + 21, g->term_col / 3 - 8);
    printw("Timer : ");
    printw(g->minutes < 10 ? "0%d:" : "%d:", g->minutes);
    printw(g->seconds < 10 ? "0%d" : "%d", g->seconds);
}

int highscore_get(tetris_t *g)
{
    FILE *file_d = fopen("score/highscore", "a+");
    char *buffer = NULL;
    size_t size_buffer = 0;
    ssize_t last_value = 0;

    if (file_d == NULL)
        return (-1);
    for (;getline(&buffer, &size_buffer, file_d) != -1; last_value++);
    buffer[last_value] = '\0';
    buffer != NULL ? g->highscore = my_getnbr(buffer) : 0;
    free(buffer);
    fclose(file_d);
    return (0);
}

int highscore_set(tetris_t *g)
{
    char *tmp = NULL;
    int file_d = 0;

    g->score > g->highscore ? g->highscore = g->score : 0;
    file_d = open("score/highscore", O_TRUNC | O_WRONLY);
    if (file_d == -1)
        return (-1);
    tmp = int_to_char(g->highscore);
    write(file_d, tmp, my_int_len(g->highscore) - 1);
    free(tmp);
    close(file_d);
    return (0);
}

int max_len_line(tetris_t *g)
{
    int max_index = 0;

    for (int i = 0; g->piece->tetrimino[i]; i++) {
        if (my_strlen(g->piece->tetrimino[i]) >= max_index)
            max_index = my_strlen(g->piece->tetrimino[i]);
    }
    return (max_index);
}
