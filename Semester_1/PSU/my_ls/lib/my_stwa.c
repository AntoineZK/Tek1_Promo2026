/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_stwa
*/

#include "my.h"

static int alpha_num(char character, char *del)
{
    for (int i = 0; del[i]; i++)
        if (character == del[i] || character == '\0')
            return (0);
    return (1);
}

static int count_words(char const *str, char *del)
{
    int nb_words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i], del) && !alpha_num(str[i + 1], del))
            nb_words++;
    }
    return (nb_words);
}

char **my_stwa(char const *str, char *del)
{
    char **word_array = malloc(sizeof(char *) * (count_words(str, del) + 1));
    int nb_words = 0;
    int i_array = 0;

    if (word_array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i], del))
            nb_words++;
        if (alpha_num(str[i], del) && !alpha_num(str[i + 1], del)) {
            word_array[i_array] = malloc(nb_words + 1);
            my_strncpy(word_array[i_array], &str[i - nb_words + 1], nb_words);
            nb_words = 0;
            i_array++;
        }
    }
    word_array[i_array] = NULL;
    return (word_array);
}

void free_double_array(char **darray)
{
    for (int i = 0; darray[i]; i++)
        free(darray[i]);
    free(darray);
}

void print_darray(char **darray)
{
    for (int i = 0; darray[i]; i++) {
        my_putstr(darray[i]);
        my_putstr("\n");
    }
}
