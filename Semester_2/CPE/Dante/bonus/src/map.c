/*
** EPITECH PROJECT, 2022
** bonus
** File description:
** map
*/

#include "dante.h"

void create_map(void)
{
    char *command = malloc(sizeof(char));

    command[0] = '\0';
    my_strcat(&command, "./generator 50 50 perfect > map.txt");
    system(command);
    free(command);
}

void print_map(dante_t *g)
{
    for (int i = 0; g->d_map[i]; i++)
        printw("%s\n", g->d_map[i]);
    mvprintw(g->player.y, g->player.x, "P");
}
