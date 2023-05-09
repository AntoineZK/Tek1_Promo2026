/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** list_management
*/

#include "lk_list.h"
#include "printf.h"

void print_list(lk_list *list)
{
    for (; list != NULL; list = list->next)
        my_printf("%s\n",list->data);
}

void free_list(lk_list *list)
{
    lk_list *tmp;

    for (; list != NULL; list = tmp) {
        tmp = list->next;
        free(list->data);
        free(list);
    }
}

int len_list(lk_list *list)
{
    int i = 0;

    for (; list != NULL; list = list->next)
        i++;
    return (i);
}
