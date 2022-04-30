/*
** EPITECH PROJECT, 2021
** pushswap_algo
** File description:
** pushswap_algo
*/

#include "../include/my.h"
#include "../include/pushswap.h"

int sort_order(int argc, linklist **list_a)
{
    linklist *temp = *list_a;
    int i = 0;
    int order = argc - 1;

    for (; temp->next != NULL && temp->value <= temp->next->value; i++)
        temp = temp->next;
    i++;
    if (i == order) {
        my_putchar('\n');
        return (0);
    }
    return (1);
}

void pushswap(linklist **list_a, linklist **list_b, int argc)
{
    int smallest;
    int nb_elem = nbr_elem_list(*list_a, 0);

    while (nb_elem > 1) {
        smallest = smallest_nb(*list_a);
        while ((*list_a)->value != smallest) {
            rotate_a(list_a);
            my_putchar(' ');
        }
        push_b(list_b, list_a);
        my_putchar(' ');
        nb_elem = nbr_elem_list(*list_a, 0);
    }
    push_b(list_b, list_a);
    my_putchar(' ');
    for (int i = 0; i < argc - 2; i++) {
        push_a(list_a, list_b);
        my_putchar(' ');
    }
    push_a(list_a, list_b);
}

int main(int argc, char **argv)
{
    linklist *list_a = NULL;
    linklist *list_b = NULL;
    linklist *element = NULL;
    int fail = 0;

    list_a = fill_linklist(argc, argv, list_a, element);
    if (argc < 2) {
        my_putstr("Not enough arg");
        my_putchar('\n');
        return (0);
    }
    fail = sort_order(argc, &list_a);
    if (fail == 0) {
        return (0);
    } else {
        pushswap(&list_a, &list_b, argc);
        my_putchar('\n');
        return (0);
    }
}
