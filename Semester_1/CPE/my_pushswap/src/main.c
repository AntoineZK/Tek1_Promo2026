/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** main
*/

#include "general.h"

lk_list *algorithme(general_t *g)
{
    int smallest = 0;
    lk_list *tmp_list = g->list;
    lk_list *tmp = NULL;

    while (nbr_element(tmp_list) > 0) {
        smallest = smallest_data(tmp_list);
        while (tmp_list->data != smallest) {
            tmp_list = rotate_to_end(tmp_list);
            my_printf("ra ");
        }
        push_to_list(&tmp_list, &tmp);
        my_printf("pb ");
    }
    while (nbr_element(tmp) > 1) {
        push_to_list(&tmp, &tmp_list);
        my_printf("pa ");
    }
    push_to_list(&tmp, &tmp_list);
    my_printf("pa\n");
    return (tmp_list);
}

int main(int ac, char **av)
{
    general_t *g = malloc(sizeof(general_t));

    g = init_struct(g, av);
    g->list = algorithme(g);
    free_list(g->list);
    free(g);
    return (0);
}
