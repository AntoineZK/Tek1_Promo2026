/*
** EPITECH PROJECT, 2021
** pushswap_utils.c
** File description:
** pushswap utils
*/

#include "../include/my.h"
#include "../include/pushswap.h"

linklist *fill_linklist(int argc, char **argv, linklist *list, linklist *elmt)
{
    for (int i = argc - 1; i > 0; i--) {
        elmt = malloc(sizeof(linklist *));
        elmt->value = my_getnbr(argv[i]);
        elmt->next = list;
        list = elmt;
    }
    return (list);
}

void print_list(linklist *list)
{
    while (list != NULL) {
        my_put_nbr(list->value);
        my_putchar(' ');
        list = list->next;
    }
}

int nbr_elem_list(linklist *list, int i)
{
    if (list == NULL) {
        i = 0;
        return (i);
    } else {
        while (list != NULL) {
            i++;
            list = list->next;
        }
        return (i);
    }
}

int smallest_nb(linklist *list_a)
{
    int tmp = list_a->value;
    int i = 0;

    list_a = list_a->next;
    while (list_a != NULL) {
        if (list_a->value < tmp) {
            tmp = list_a->value;
            i++;
        }
        list_a = list_a->next;
    }
    return (tmp);
}
