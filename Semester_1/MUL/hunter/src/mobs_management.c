/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** mobs_management
*/

#include "../include/my.h"
#include "../include/myhunter.h"

hunter_t *revive_mobs(hunter_t *hunter)
{
    hunter = revive_goblin(hunter);
    hunter = revive_wyvern(hunter);
    return (hunter);
}

hunter_t *kill_mobs(hunter_t *hunter)
{
    hunter = kill_the_wyvern(hunter);
    sfSound_play(hunter->zelda_bow);
    hunter = kill_the_goblin(hunter);
    sfSound_play(hunter->zelda_bow);
    return (hunter);
}
