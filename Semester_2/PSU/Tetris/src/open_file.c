/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** open_file
*/

#include "../include/tetris.h"
#include "../include/my.h"

int find_size(char *path)
{
    struct stat sb;
    stat(path, &sb);
    return (sb.st_size);
}

char **tetris_error(char *filepath)
{
    struct stat statbuff;
    int file_d = 0;
    char *map_buffer = NULL;
    char **tetriminos = NULL;

    stat(filepath, &statbuff);
    if ((file_d = open(filepath, O_RDONLY)) == - 1)
        return (NULL);
    map_buffer = malloc(sizeof(char) * statbuff.st_size + 1);
    if (read(file_d, map_buffer, statbuff.st_size) <= 0)
        return (NULL);
    close(file_d);
    map_buffer[statbuff.st_size] = 0;
    tetriminos = parse(map_buffer, '\n');
    free(map_buffer);
    return (tetriminos);
}

char *open_file(char *path)
{
    struct stat statbuff;
    int file_d = 0;
    char *map_buffer = NULL;

    stat(path, &statbuff);
    if ((file_d = open(path, O_RDONLY)) == - 1)
        return (NULL);
    map_buffer = malloc(sizeof(char) * statbuff.st_size + 1);
    if (read(file_d, map_buffer, statbuff.st_size) <= 0)
        return (NULL);
    close(file_d);
    map_buffer[statbuff.st_size] = 0;
    return (map_buffer);
}

int my_isnum(char *num)
{
    for (int i = 0; num[i]; i++) {
        if (num[i] < '0' || num[i] > '9')
            return (0);
    }
    return (1);
}
