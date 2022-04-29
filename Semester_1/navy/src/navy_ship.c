/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_map
*/

#include "../include/my.h"
#include "../include/navy.h"

static int get_nbline(char const *buffer)
{
    int nbline = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nbline++;
    }
    return (nbline);
}

char *open_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    char *buffer = malloc(sizeof(char) * 33);
    int byte = read(fd, buffer, 32);
    if (byte <= 0)
        return (NULL);
    buffer[byte] = 0;
    close(fd);
    return (buffer);
}

int check_ship(char *buffer)
{
    if (my_getnbr(buffer) < 2 || my_getnbr(buffer) > 5)
        return 0;
    if (buffer[2] < 'A' || buffer[2] > 'H')
        return 0;
    if (buffer[3] < '1' || buffer[3] > '8')
        return 0;
    if (buffer[5] < 'A' || buffer[5] > 'H')
        return 0;
    if (buffer[6] < '1' || buffer[6] > '8')
        return 0;
    return (check_ship_two(buffer));
}

ship get_ship(char *buffer)
{
    ship current = {0};
    current.length = my_getnbr(buffer);
    current.first_square = malloc(sizeof(char) * 3);
    current.first_square[0] = buffer[2];
    current.first_square[1] = buffer[3];
    current.first_square[2] = 0;
    current.last_square = malloc(sizeof(char) * 3);
    current.last_square[0] = buffer[5];
    current.last_square[1] = buffer[6];
    current.last_square[2] = 0;
    return (current);
}

ship *load_ships(char *buffer)
{
    int nbline = get_nbline(buffer);
    if (nbline != 4)
        return (NULL);
    ship *ships = malloc(sizeof(ship) * nbline);
    for (int i = 0; i < nbline; i++) {
        if (!check_ship(buffer))
            return NULL;
        ships[i] = get_ship(buffer);
        buffer += 8;
    }
    if (checks_ships(ships))
        return (ships);
    else
        return (NULL);
}
