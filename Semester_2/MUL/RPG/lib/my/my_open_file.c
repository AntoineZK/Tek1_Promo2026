/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_open_file
*/

#include "my.h"

char *my_open_file(char const *filename)
{
    char *buffer = malloc(sizeof(char));
    buffer[0] = '\0';
    char *line = NULL;
    long unsigned int size = 0;
    ssize_t byte = 0;
    FILE *file = fopen(filename, "r");
    if (!file) {
        free(buffer);
        return (NULL);
    }
    while ((byte = getline(&line, &size, file)) >= 0)
        my_strcat_dyn(&buffer, line);
    fclose(file);
    free(line);
    return (buffer);
}
