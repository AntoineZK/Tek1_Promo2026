/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** lk_list
*/

#pragma once

#include "my.h"

typedef struct lk_list_s {
    char *data;
    struct lk_list_s *next;
} lk_list;

lk_list *add_node_front(lk_list *list, char *data);
lk_list *add_node_last(lk_list *list, char *data);
lk_list *pop_node_front(lk_list *list);
lk_list *pop_node_last(lk_list *list);
void print_list(lk_list *list);
void free_list(lk_list *list);
