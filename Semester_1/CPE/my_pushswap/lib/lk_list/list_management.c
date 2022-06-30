/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** list_management
*/

#include "lk_list.h"
#include "printf.h"

int nbr_element(lk_list *list)
{
    int nbr = 0;

    for (; list != NULL; list = list->next)
        nbr++;
    return (nbr);
}

int smallest_data(lk_list *list)
{
    int tmp = list->data;
    int i = 0;

    list = list->next;
    while (list != NULL) {
        if (list->data < tmp) {
            tmp = list->data;
            i++;
        }
        list = list->next;
    }
    return (tmp);
}

void print_list(lk_list *list)
{
    for (; list != NULL; list = list->next)
        my_printf("%d\n",list->data);
}

void free_list(lk_list *list)
{
    lk_list *tmp;

    for (; list != NULL; list = tmp) {
        tmp = list->next;
        free(list);
    }
}
