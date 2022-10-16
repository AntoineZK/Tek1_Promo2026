/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** linked_list
*/

#include "my.h"

int linked_list_len(linked_list *list)
{
    int len = 0;
    for (; list != NULL; len++)
        list = list->next;
    return (len);
}

void linked_list_add(linked_list *list, char *data)
{
    while (list->next)
        list = list->next;
    linked_list *next_node = malloc(sizeof(linked_list));
    next_node->data = data;
    next_node->next = NULL;
    list->next = next_node;
}

void linked_list_remove(linked_list *list, char *data)
{
    linked_list *previous = NULL;
    while (list) {
        if (my_str_is_equal(list->data, data)) {
            previous->next = list->next;
            return;
        }
        previous = list;
        list = list->next;
    }
}

linked_list *array_to_linked_list(char **array)
{
    linked_list *list = malloc(sizeof(linked_list));
    list->data = array[0];
    list->next = NULL;
    for (int i = 1; array[i] != NULL; ++i)
        linked_list_add(list, array[i]);
    return (list);
}

char **linked_list_to_array(linked_list *list)
{
    char **array = malloc(sizeof(char *) * (linked_list_len(list) + 1));
    int i = 0;
    for (; list; ++i) {
        array[i] = list->data;
        list = list->next;
    }
    array[i] = NULL;
    return (array);
}
