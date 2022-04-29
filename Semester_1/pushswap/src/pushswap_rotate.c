/*
** EPITECH PROJECT, 2021
** pushswap sort
** File description:
** pushswap
*/

#include "../include/my.h"
#include "../include/pushswap.h"

void rotate_a(linklist **list_a)
{
    linklist* first = *list_a;
    linklist* last = *list_a;

    if ((*list_a)->next == NULL)
        return;
    while (last->next != NULL)
        last = last->next;
    *list_a = first->next;
    first->next = NULL;
    last->next = first;
    my_putstr("ra");
}

void rotate_b(linklist **list_b)
{
    linklist* first = *list_b;
    linklist* last = *list_b;

    if ((*list_b)->next == NULL)
        return;
    while (last->next != NULL)
        last = last->next;
    *list_b = first->next;
    first->next = NULL;
    last->next = first;
    my_putstr("rb");
}

void rotate_r(linklist **list_a, linklist **list_b)
{
    rotate_a(list_a);
    rotate_b(list_b);
    my_putstr("rr");
}
