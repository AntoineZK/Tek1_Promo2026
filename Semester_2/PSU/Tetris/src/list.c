/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** list
*/

#include "tetris.h"

int list_len(lk_list *list)
{
    lk_list *ltmp = list;
    int i = 0;
    for (; ltmp != NULL; ltmp = ltmp->next, i++);
    return (i);
}
