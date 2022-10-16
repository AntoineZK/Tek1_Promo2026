/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** find_coord
*/

#include "rpg.h"

int nb_line(char **map)
{
    int nb_l = 0;

    for (; map[nb_l]; nb_l++);
    return (nb_l);
}

sfVector2f find_char(char **map, char character)
{
    sfVector2f coord;
    int break_val = 0;

    coord.x = 0;
    coord.y = 0;
    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            map[y][x] == character ? coord.x = x * 128 : 0;
            map[y][x] == character ? coord.y = y * 128 : 0;
            map[y][x] == character ? break_val = 1 : 0;
        }
        if (break_val)
            break;
    }
    return (coord);
}

sfVector2i double_to_int(double x, double y, int to_divide, char **map)
{
    sfVector2i cord = {0, 0};

    x /= to_divide;
    y /= to_divide;
    cord.x = x;
    cord.y = y;
    cord.y < 0 ? cord.y = 0 : 0;
    cord.x < 0 ? cord.x = 0 : 0;
    cord.y >= nb_line(map) ? cord.y = nb_line(map) - 1 : 0;
    cord.x >= my_strlen(map[cord.y]) ? cord.x = my_strlen(map[cord.y]) - 1 : 0;
    return (cord);
}

int find_char_map(char **map, sfVector2f value, char to_find, int hitbox)
{
    sfVector2i cord = {0, 0};

    cord = double_to_int(value.x, value.y, 128, map);
    if (map[cord.y][cord.x] == to_find)
        return (1);
    cord = double_to_int(value.x + hitbox, value.y, 128, map);
    if (map[cord.y][cord.x] == to_find)
        return (1);
    cord = double_to_int(value.x, value.y + hitbox, 128, map);
    if (map[cord.y][cord.x] == to_find)
        return (1);
    cord = double_to_int(value.x + hitbox, value.y + hitbox, 128, map);
    if (map[cord.y][cord.x] == to_find)
        return (1);
    return (0);
}
