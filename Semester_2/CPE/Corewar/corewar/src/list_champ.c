/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** list_champ
*/

#include "../include/corewar.h"

champions_t *init_node(champions_t *champ)
{
    champ->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));
    champ->comment == NULL ? exit(84) : 0;
    champ->name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
    champ->name == NULL ? exit(84) : 0;
    champ->number = 0;
    champ->prog_size = 0;
    champ->ptr = NULL;
    champ->cycles = 0;
    champ->cycle_to_die = 0;
    champ->instruction = 0;
    champ->alive = 1;
    for (int i = 0; i < REG_NUMBER; i++)
        champ->registre[i] = 0;
    for (int i = 0; i <= 4; i++)
        champ->instru[i].value = 0;
    champ->next = NULL;
    return (champ);
}

champions_t *add_value(champions_t *list, vm_header_t *header, args_t *arg)
{
    list->ptr = fopen(arg->name, "rb");
    list->number = arg->number;
    list->next = NULL;
    list->name = my_strcpy(list->name, header->name);
    list->comment = my_strcpy(list->comment, header->comment);
    list->prog_size = header->prog_size;
    list->code = malloc(sizeof(u_char) * (list->prog_size + 2));
    list->code == NULL ? exit(84) : 0;
    list->code = my_strucpy(list->code, header->code, header->prog_size);
    return (list);
}

void add_champ(champions_t **list, vm_header_t *header, args_t *arg)
{
    champions_t *tmp = *list;
    champions_t *new_node = malloc(sizeof(champions_t));

    new_node == NULL ? exit(84) : 0;
    if (!(*list)) {
        *list = malloc(sizeof(champions_t));
        *list == NULL ? exit(84) : 0;
        (*list) = init_node(*list);
        (*list) = add_value(*list, header, arg);
        (*list)->next = NULL;
        free(new_node);
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    new_node = init_node(new_node);
    new_node = add_value(new_node, header, arg);
    new_node->next = NULL;
    tmp->next = new_node;
}

void print_champ(champions_t *champ)
{
    champions_t *tmp = champ;

    while (tmp != NULL) {
        my_printf("Name = %s : ", tmp->name);
        my_printf("Number = %d : ", tmp->number);
        my_printf("Comment = %s\n", tmp->comment);
        tmp = tmp->next;
    }
}

void free_champ(champions_t *arg)
{
    champions_t *tmp = NULL;

    while (arg) {
        tmp = arg;
        arg = arg->next;
        free(tmp->comment);
        free(tmp->name);
        free(tmp->code);
        if (tmp->ptr != NULL)
            fclose(tmp->ptr);
        free(tmp);
    }
    free (arg);
}
