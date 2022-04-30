/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-navy-antoine.khalidy
** File description:
** navy_ship2
*/

#include "../include/my.h"
#include "../include/navy.h"

static int checks_ship3(ship * ships, int i)
{
    for (int j = 0; ships[j].length >= 1 && ships[j].length <= 8 ; j++)
        if (ships[i].length == ships[j].length && i != j)
            return (0);
    return (1);
}

int checks_ships(ship *ships)
{
    for (int i = 0; ships[i].length >= 1 && ships[i].length <= 8 ; i++) {
        if (checks_ships3(ships, i) == 0)
            return (0);
        if (ships[i].length < 2 || ships[i].length > 5)
            return (0);
    }
    return (1);
}

int check_ship_two(char *buffer)
{
    int difference = 0;
    if (buffer[2] == buffer[5]) {
        for (;buffer[3] + difference < buffer[6]; difference++);
        difference++;
    } else {
        for (;buffer[2] + difference < buffer[5]; difference++);
        difference++;
    }
    if (difference != my_getnbr(buffer))
        return (0);
    if (buffer[2] != buffer[5] && buffer[3] != buffer[6])
        return (0);
    return (1);
}
