/*
** EPITECH PROJECT, 2021
** pushswap revrotate
** File description:
** revrotate
*/

#include "../include/my.h"
#include "../include/pushswap.h"

void reverse_rotate_a(linklist **list_a)
{
    linklist *last = *list_a;
    linklist *beforelast = NULL;

    if ((*list_a)->next == NULL)
        return;
    while (last->next != NULL) {
        beforelast = last;
        last = last->next;
    }
    beforelast->next = NULL;
    last->next = *list_a;
    *list_a = last;
}

void reverse_rotate_b(linklist **list_b)
{
    linklist *last = *list_b;
    linklist *beforelast = NULL;

    if ((*list_b)->next == NULL)
        return;
    while (last->next != NULL) {
        beforelast = last;
        last = last->next;
    }
    beforelast->next = NULL;
    last->next = *list_b;
    *list_b = last;
}

void reverse_rotate_r(linklist **list_a, linklist **list_b)
{
    reverse_rotate_a(list_a);
    reverse_rotate_b(list_b);
    my_putstr("rrr ");
}
