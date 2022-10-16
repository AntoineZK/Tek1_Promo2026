/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** arg_list
*/

#include "../include/corewar.h"

args_t *add_node(args_t *list, char *name, int nb_player, int address)
{
    args_t *new = malloc(sizeof(args_t));
    args_t *tmp = list;

    if (new == NULL)
        return (NULL);
    new->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    new->name == NULL ? exit(84) : 0;
    new->name = my_strcpy(new->name, name);
    new->number = nb_player;
    new->load_adress = address;
    new->next = NULL;
    if (list == NULL)
        return (new);
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
    return (list);
}

void print_list(args_t *list)
{
    args_t *tmp = list;

    for (; tmp != NULL; tmp = tmp->next) {
        printf("Name %s : ", tmp->name);
        printf("Number %d : ", tmp->number);
        printf("Load adress %d\n", tmp->load_adress);
    }

}

static int arg_n_a(corewar_t *g, char **av, int i)
{
    if (my_strcmp(av[i], "-n")) {
        i = arg_n(g, av, i);
        if (i == -1)
            return (-1);
    }
    if (my_strcmp(av[i], "-a")) {
        i = arg_a(g, av, i);
        if (i == -1)
            return (-1);
    }
    return (i);
}

int arg_list_handler(corewar_t *g, char **av, int i)
{
    i = arg_n_a(g, av, i);
    if (i == -1)
        return (-1);
    if (my_strstr(".cor", av[i])) {
        g->nb_player++;
        if (g->tmp_nb_player != -1) {
            g->list = add_node(g->list, av[i], g->tmp_nb_player,
            g->load_adress);
            g->tmp_nb_player = -1;
        } else
            g->list = add_node(g->list, av[i], g->nb_player, g->load_adress);
    }
    return (i);
}

void free_arg(args_t *arg)
{
    args_t *tmp = NULL;

    while (arg) {
        tmp = arg;
        arg = arg->next;
        free(tmp->name);
        free(tmp);
    }
    free(arg);
}
