/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_write_file
*/

#include "my.h"

int my_write_file(char const *filename, char const *data)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0)
        return (1);
    write(fd, data, my_strlen(data));
    close(fd);
    return (0);
}
