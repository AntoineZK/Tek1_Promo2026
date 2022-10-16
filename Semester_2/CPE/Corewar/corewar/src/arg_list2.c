/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** arg_list2
*/

#include "../include/corewar.h"

args_t *add_argument(args_t *list, char *name, int address, int nb_player)
{
    list->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    list->name == NULL ? exit(84) : 0;
    list->name = my_strcpy(list->name, name);
    list->number = nb_player;
    list->load_adress = address;
    list->next = NULL;
    return (list);
}
