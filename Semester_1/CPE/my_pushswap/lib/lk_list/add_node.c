/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** add_node
*/

#include "lk_list.h"

static lk_list *add_data(lk_list *list, char *data)
{
    list->data = my_atoi(data);
    list->next = NULL;
    return (list);
}

lk_list *add_node_front(lk_list *list, char *data)
{
    lk_list *new = malloc(sizeof(lk_list));

    new = add_data(new, data);
    new->next = list;
    return (new);
}

lk_list *add_node_last(lk_list *list, char *data)
{
    lk_list *new = malloc(sizeof(lk_list));

    new = add_data(new, data);
    if (list == NULL)
        return (new);
    lk_list *tmp = list;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return (list);
}
