/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/generator.h"

int main(int argc, char **argv)
{
    if (error_gest(argc, argv) == 84)
        return (84);
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    if (x <= 0 || y <= 0)
        return (84);
    char **map = malloc(sizeof(char *) * (y + 2));
    alloc_map(map, x, y);
    fill_map(map, x, y);
    if (!(argc == 4 && strcmp(argv[3], "perfect") == 0))
        make_imperfect(map, x, y);
    show_map(map);
    return (0);
}
