/*
** EPITECH PROJECT, 2022
** nw_pushswap [WSL : Ubuntu-20.04]
** File description:
** push_to_list
*/

#include "lk_list.h"

void push_to_list(lk_list **from, lk_list **to)
{
    lk_list *tmp = *from;

    *from = (*from)->next;
    tmp->next = *to;
    *to = tmp;
}
