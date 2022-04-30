/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H
    #define PUSHSWAP_H

typedef struct linklist {
    int value;
    struct linklist *next;
} linklist;

void swap_a(linklist *list_a);
void swap_b(linklist *list_b);
void swap_c(linklist *list_a, linklist *list_b);
void rotate_a(linklist **list_a);
void rotate_b(linklist **list_b);
void rotate_r(linklist **list_a, linklist **list_b);
void push_a(linklist **list_a, linklist **list_b);
void push_b(linklist **list_b, linklist **list_a);
void reverse_rotate_a(linklist **list_a);
void reverse_rotate_b(linklist **list_b);
void reverse_rotate_r(linklist **list_a, linklist **list_b);
linklist *fill_linklist(int argc, char **argv, linklist *list, linklist *elmt);
void print_list(linklist *list);
int nbr_elem_list(linklist *list, int i);
int smallest_nb(linklist *list_a);

#endif
