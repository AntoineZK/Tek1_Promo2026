/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** description
*/

#include "../include/sokoban.h"

int description(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map");
    my_putstr(", containing '#' for walls,\n");
    my_putstr("          'P' for the player, 'X' ");
    my_putstr("for boxes and 'O' for storage locations.\n");
    return (0);
}
