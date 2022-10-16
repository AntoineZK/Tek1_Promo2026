/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** map
*/

#include "../include/sokoban.h"

void showmap(sokoban_t *soko)
{
    for (int i = 0; soko->map[i]; i++)
        printw("%s\n", soko->map[i]);
    for (int i = 0; soko->boxes[i]; i++) {
        move(soko->boxes[i]->y, soko->boxes[i]->x);
        printw("X");
    }
}

int map_error(sokoban_t *solv, char *filepath)
{
    stat(filepath, &solv->statbuff);
    if ((solv->file_d = open(filepath, O_RDONLY)) == - 1)
        return (1);
    solv->map_buffer = malloc(sizeof(char) * solv->statbuff.st_size + 1);
    if (read(solv->file_d, solv->map_buffer, solv->statbuff.st_size) <= 0) {
        free(solv);
        return (1);
    }
    close(solv->file_d);
    solv->map_buffer[solv->statbuff.st_size] = 0;
    solv->map = my_str_to_word_array(solv->map_buffer);
    return (0);
}

int check_map(sokoban_t *soko)
{
    for (int i = 0; soko->map_buffer[i] != '\0'; i++) {
        if (soko->map_buffer[i] == 'P' ||
        soko->map_buffer[i] == 'X' ||
        soko->map_buffer[i] == 'O' ||
        soko->map_buffer[i] == '#' ||
        soko->map_buffer[i] == ' ' ||
        soko->map_buffer[i] == '\n')
            continue;
        else
            return (1);
    }
    return (0);
}

void print_last_loop(sokoban_t *soko)
{
    erase();
    showmap(soko);
    move(soko->player.y, soko->player.x);
    printw("P");
    refresh();
    usleep(100000);
    endwin();
}
