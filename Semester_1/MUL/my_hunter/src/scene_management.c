/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myhunter-antoine.khalidy
** File description:
** scene_management
*/

#include "../include/my.h"
#include "../include/myhunter.h"

void scene_management(hunter_t *hunter)
{
    hunter->scene == 0 ? menu_draw(hunter) : 0;
    hunter->scene == 1 ? difficulty_draw(hunter) : 0;
    hunter->scene == 2 ? easy_draw(hunter) : 0;
    hunter->scene == 3 ? normal_draw(hunter) : 0;
    hunter->scene == 4 ? hard_draw(hunter) : 0;
    hunter->scene == 5 ? lose_draw(hunter) : 0;
    hunter->scene == 6 ? win_draw(hunter) : 0;
}
