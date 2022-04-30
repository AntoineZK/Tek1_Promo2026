/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_description
*/

#include "../include/my.h"
#include "../include/navy.h"

int description(void)
{
    my_putstr("\nUSAGE \n \
    ./navy [first_player_pid] navy_positions \n\
DESCRIPTION \n\
    first_player_pid: only for the 2nd player. pid of the first player. \n\
    navy_positions: file representing the positions of the ships.\n");
    return (0);
}
