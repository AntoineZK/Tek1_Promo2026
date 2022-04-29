/*
** EPITECH PROJECT, 2021
** pushswap sort
** File description:
** pushswap
*/

#include "../include/my.h"
#include "../include/pushswap.h"

void swap_a(linklist *list_a)
{
    int temp = list_a->value;
    list_a->value = list_a->next->value;
    list_a->next->value = temp;
    my_putstr("sa");
}

void swap_b(linklist *list_b)
{
    int temp = list_b->value;
    list_b->value = list_b->next->value;
    list_b->next->value = temp;
    my_putstr("sb");
}

void swap_c(linklist *list_a, linklist *list_b)
{
    swap_a(list_a);
    swap_b(list_b);
    my_putstr("sc");
}
