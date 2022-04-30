/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_map
*/

#include "../include/navy.h"
#include "../include/my.h"

char **load_default_map(void)
{
    char **map = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
        map[i][8] = 0;
    }
    return (map);
}

char **load_map(ship *ships)
{
    char **map = load_default_map();
    for (int i = 0; ships[i].length >= 1 && ships[i].length <= 8 ; i++) {
        int coordinate[2] = {ships[i].first_square[0] - 'A',
                            ships[i].first_square[1] - '1'};
        int horizontal = ships[i].first_square[0] - ships[i].last_square[0]
                                                        != 0 ? 1 : 0;
        for (int j = 0; j < ships[i].length; j++) {
            map[coordinate[1]][coordinate[0]] = ships[i].length + 48;
            horizontal ? coordinate[0]++ : coordinate[1]++;
        }
    }
    return (map);
}

void show_map(char **map)
{
    for (int i = 0; i < 10; i++) {
        if (i == 0)
            my_putstr(" |A B C D E F G H\n");
        else if (i == 1)
            my_putstr("-+---------------\n");
        else {
            codingstyle3(i, map);
        }
    }
}
