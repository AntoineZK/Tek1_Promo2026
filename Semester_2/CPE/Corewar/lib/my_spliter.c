/*
** EPITECH PROJECT, 2021
** lib/my/my_str_to_word_array
** File description:
** hello world?
*/

#include <stdlib.h>
#include "../include/my.h"

int count_word(char *str, char split)
{
    int nb = 0;
    int i = 0;

    for (; str[i]; i++)
        if (str[i] != split && (str[i + 1] == split || str[i + 1] == '\0'))
            nb++;

    return (nb);
}

int word_len(char const *str, char split)
{
    int len = 0;
    int i = 0;

    for (; str[i] == split; i++);
    for (; str[i] != split && str[i] != '\0'; i++, len++);

    return (len);
}

char *fill_tab(char *str, char *tab, char split)
{
    int i = 0;
    int j = 0;

    for (; str[i] == split; i++);
    for (; str[i] != split && str[i] != '\0'; i++, j++)
        tab[j] = str[i];
    tab[j] = '\0';

    return (tab);
}

int count_len(char const *str, char split)
{
    int i = 0;

    for (; str[i] == split; i++);
    for (; str[i] != split && str[i] != '\0'; i++);

    return (i);
}

char **my_spliter(char *str, char const split)
{
    if (str == NULL)
        return NULL;
    int nb_word = count_word(str, split);
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    int i = 0;

    if (result == NULL)
        return (NULL);
    for (; i < nb_word; i++) {
        result[i] = malloc(sizeof(char) * (word_len(str, split) + 1));
        result[i] = fill_tab(str, result[i], split);
        str = str + count_len(str, split);
    }
    result[i] = NULL;

    return (result);
}
