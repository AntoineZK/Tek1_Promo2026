/*
** EPITECH PROJECT, 2022
** Tek1
** File description:
** my_stwa
*/

#include "my.h"

static char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    for (; i != n; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

static int alpha_num(char character, char del)
{
    int is_alphanum = 1;

    if (character == del || character == '\0')
        is_alphanum = 0;
    return (is_alphanum);
}

static int count_words(char const *str, char del)
{
    int nb_words = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (alpha_num(str[i], del) && !alpha_num(str[i + 1], del))
            nb_words++;
    }
    return (nb_words);
}

char **my_stwa(char const *str, char del)
{
    char **word_array = malloc(sizeof(char *) * (count_words(str, del) + 1));
    int nb_words = 0;
    int i_array = 0;

    if (word_array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; ++i) {
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
    for (int i = 0; darray[i]; ++i)
        free(darray[i]);
    free(darray);
}
