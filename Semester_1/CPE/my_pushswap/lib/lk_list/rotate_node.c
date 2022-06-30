/*
** EPITECH PROJECT, 2022
** nw_pushswap [WSL : Ubuntu-20.04]
** File description:
** rotate_node
*/

#include "lk_list.h"

lk_list *rotate_to_end(lk_list *list)
{
    lk_list *first = list;
    lk_list *last = list;

    if (list->next == NULL)
        return (list);
    for (; last->next != NULL; last = last->next);
    list = first->next;
    first->next = NULL;
    last->next = first;
    return (list);
}