/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** alloc_dstar_int
*/

#include "../include/my.h"

int **alloc_dstar_int(int nb_l, int nb_c, int **to_alloc)
{
    to_alloc = malloc(sizeof(int *) * nb_l);
    if (to_alloc == NULL)
        return (NULL);
    for (int i = 0; i < nb_l; i++)
        to_alloc[i] = malloc(sizeof(int) * nb_c);
    if (to_alloc == NULL)
        return (NULL);
    return (to_alloc);
}

void free_dint_array(int **darray, int nb_line)
{
    for (int i = 0; i < nb_line; i++)
        free(darray[i]);
    free(darray);
}
