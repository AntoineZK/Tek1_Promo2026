/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-mysokoban-antoine.khalidy
** File description:
** bonus
*/

#include "../include/sokoban.h"
#include "../include/bonus.h"

int bonus(void)
{
    char *bonus_map = "";
    for (int i = 1; i != 10; i++) {
        bonus_map = my_strcat("map/map", int_to_char(i));
        bonus_map = my_strcat(bonus_map, ".txt");
        if (launch_bonus(bonus_map)) {
            my_putstr("You lost try again ...\n");
            break;
        } else {
            bonus_map = "";
        }
    }
    bonus_map = my_strcat("map/map", int_to_char(10));
    bonus_map = my_strcat(bonus_map, ".txt");
    if (launch_bonus(bonus_map)) {
        my_putstr("You lost try again ...\n");
        return (1);
    } else {
        return (my_putstr("Good Job Your The King\n"));
    }
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h"))
        return (description_0_bonus());
    else
        return (bonus());
}
