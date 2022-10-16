/*
** EPITECH PROJECT, 2022
** my_link_list
** File description:
** my_link_list
*/

#include "../include/my.h"

linklist *fill_linklist(int argc, char **argv, linklist *list, linklist *elmt)
{
    for (int i = argc - 1; i > 0; i--) {
        elmt = malloc(sizeof(linklist));
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

int nbr_elem_list(linklist *list)
{
    int i = 0;

    if (list == NULL) {
        return (i);
    } else {
        while (list != NULL) {
            i++;
            list = list->next;
        }
        return (i);
    }
}
