/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** linked_list.c
*/

#include "../include/asm.h"

void free_linked_list(asm_list_t *list)
{
    asm_list_t *stock = NULL;

    while (list != NULL) {
        stock = list;
        list = list->next;
        free_double_array(stock->tab);
        free(stock->line);
        free(stock);
    }
}

static int search_word(char *line, char *word)
{
    int len_word = my_strlen(word);
    int len_line = my_strlen(line);
    int flag = 0;
    int i = 0;

    for (; i != (len_line - len_word + 1) && flag == 0; i++, line++) {
        if (my_strncmp(line, word, len_word) && line[len_word] == ':')
            flag = 1;
    }
    for (int j = 0; j != i; j++, line--);
    if (flag == 1)
        return (EXIT_OK);
    return (EXIT_ERR);
}

int search_list_char(asm_list_t *list, char *word)
{
    asm_list_t *backup = list;
    int i = 0;
    int flag = 0;

    for (; flag == 0; list = list->next) {
        if (search_word(list->line, word) == EXIT_OK)
            flag = 1;
        else
            i++;
    }
    list = backup;
    return (i);
}

asm_list_t *add_nod_list(asm_list_t *list, char *line)
{
    asm_list_t *nod = malloc(sizeof(asm_list_t));
    asm_list_t *backup = NULL;

    if (nod == NULL)
        return (NULL);
    backup = list;
    nod->bitmask = 0;
    nod->line = NULL;
    nod->line = my_strdup(line);
    nod->size = 0;
    nod->next = NULL;
    if (list == NULL)
        return (nod);
    else {
        for (; list->next != NULL; list = list->next);
        list->next = nod;
        list = backup;
    }
    return (list);
}
