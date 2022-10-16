/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** map
*/

#include "../include/sokoban.h"

sokoban_t *open_map(sokoban_t *soko, char *filepath)
{
    soko->map_buffer = "";
    char *line = NULL;
    size_t line_buffer = 0;
    FILE *file = fopen(filepath, "r");
    int line_size = getline(&line, &line_buffer, file);

    while (line_size >= 0) {
        soko->map_buffer = my_strcat(soko->map_buffer, line);
        line_size = getline(&line, &line_buffer, file);
    }
    soko->map = my_str_to_word_array(soko->map_buffer);
    free(line);
    fclose(file);
    return (soko);
}

void showmap(sokoban_t *soko)
{
    for (int i = 0; soko->map[i]; i++)
        printw("%s\n", soko->map[i]);
    for (int i = 0; soko->boxes[i]; i++) {
        move(soko->boxes[i]->y, soko->boxes[i]->x);
        printw("X");
    }
}

int map_error(sokoban_t *soko, char *filepath)
{
    stat(filepath, &soko->statbuff);
    if ((soko->file_d = open(filepath, O_RDONLY)) == - 1)
        return (1);
    soko->cmap = malloc(sizeof(char) * soko->statbuff.st_size);
    if (read(soko->file_d, soko->cmap, soko->statbuff.st_size) <= 0) {
        free(soko);
        return (1);
    }
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
