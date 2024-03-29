/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** pop_node
*/

#include "lk_list.h"

static lk_list *pop_data_front(lk_list *list)
{
    free(list->data);
    free(list);
    return (list);
}

lk_list *pop_node_front(lk_list *list)
{
    lk_list *tmp = list;

    list = list->next;
    tmp = pop_data_front(tmp);
    return (list);
}

static lk_list *pop_data_last(lk_list *list)
{
    free(list->next->data);
    free(list->next);
    return (list);
}

lk_list *pop_node_last(lk_list *list)
{
    lk_list *tmp = list;

    for (; tmp->next->next != NULL; tmp = tmp->next);
    tmp = pop_data_last(tmp);
    tmp->next = NULL;
    return (list);
}

lk_list *pop_node_index(lk_list *list, int position)
{
    if (position == len_list(list))
        return (pop_node_last(list));
    else if (position == 0)
        return (pop_node_front(list));
    lk_list *previous = list;
    lk_list *current = list;
    for (;position != 1; position--) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current->data);
    free(current);
    current = NULL;
    return list;
}
