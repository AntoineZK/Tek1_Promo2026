/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** find_coord
*/

#include "../include/defender.h"

sfVector2f find_char(defender_t *def, char character)
{
    sfVector2f coord;
    coord.x = 0;
    coord.y = 0;
    int break_val = 0;

    for (int y = 0; def->map[y]; y++) {
        for (int x = 0; def->map[y][x]; x++) {
            def->map[y][x] == character ? coord.x = x * 108 : 0;
            def->map[y][x] == character ? coord.y = y * 108 : 0;
            def->map[y][x] == character ? break_val = 1 : 0;
        }
        if (break_val)
            break;
    }
    coord.x += 54;
    coord.y -= 100;
    return (coord);
}

char find_char_map(defender_t *def, double x, double y)
{
    int x_int = 0;
    int y_int = 0;
    char to_return;

    x /= 108;
    y /= 108;
    x_int = x;
    y_int = y;
    if (x_int >= 13)
        x_int = 13;
    if (y_int >= 9)
        y_int = 9;
    to_return = def->map[y_int][x_int];
    return (to_return);
}

sfVector2f center_tower(double x, double y)
{
    int x_int = 0;
    int y_int = 0;

    x /= 108;
    y /= 108;
    x_int = x;
    y_int = y;
    x_int *= 108;
    y_int *= 108;
    x_int += 54;
    y_int += 54;
    sfVector2f center;
    center.x = x_int;
    center.y = y_int;
    return (center);
}

void double_to_int(defender_t *def, double x, double y)
{
    def->x_int = 0;
    def->y_int = 0;
    x /= 108;
    y /= 108;
    def->x_int = x;
    def->y_int = y;
    def->x_int >= 13 ? def->x_int = 13 : 0;
    def->y_int >= 9 ? def->y_int = 9 : 0;
}
