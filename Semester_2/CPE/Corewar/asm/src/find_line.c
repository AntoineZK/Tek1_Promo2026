/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** find_line
*/

#include "../include/asm.h"

static int check_elem(char *elem, char *valid_char, int i)
{
    for (int j = 0; elem[j] != '\0'; j++)
        if (elem[j] != valid_char[i])
            return (EXIT_ERR);
    return (EXIT_OK);
}

static int check_valid(char *elem, char *valid_char)
{
    for (int i = 0; valid_char[i] != '\0'; i++)
        if (check_elem(elem, valid_char, i) == EXIT_ERR)
            return (EXIT_ERR);
    return (EXIT_OK);
}

static char *remove_useless_char(char *tab)
{
    char *tmp = tab;

    if (tab[0] == '\t')
        tmp++;
    return (tmp);
}

char *find_line(char **tab, char *search)
{
    int size = my_strlen(search);
    char *tmp = NULL;

    for (int i = 0; tab[i] != NULL; i++) {
        tmp = remove_useless_char(tab[i]);
        if (my_strncmp(search, tmp, size) && check_valid(tmp,
            LABEL_CHARS)) {
            return (tmp);
        }
    }
    return (NULL);
}
