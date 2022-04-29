/*
** EPITECH PROJECT, 2021
** pushswap push
** File description:
** pushswap push
*/

#include "../include/my.h"
#include "../include/pushswap.h"

void push_a(linklist **list_a, linklist **list_b)
{
    linklist *temp = malloc(sizeof(linklist *));

    temp->value = (*list_b)->value;
    temp->next = (*list_a);
    (*list_b) = (*list_b)->next;
    (*list_a) = temp;
    my_putstr("pa");
}

void push_b(linklist **list_b, linklist **list_a)
{
    linklist *temp = malloc(sizeof(linklist *));

    temp->value = (*list_a)->value;
    temp->next = (*list_b);
    (*list_a) = (*list_a)->next;
    (*list_b) = temp;
    my_putstr("pb");
}
