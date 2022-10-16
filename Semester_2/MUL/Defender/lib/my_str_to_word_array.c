/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"

int alpha_num(char character)
{
    int is_alphanum = 0;

    if (character >= 'a' && character <= 'z')
        is_alphanum = 1;
    if (character >= 'A' && character <= 'Z')
        is_alphanum = 1;
    if (character >= '0' && character <= '9')
        is_alphanum = 1;
    return (is_alphanum);
}

int count_words(char const *str)
{
    int nb_words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i]) == 1 && alpha_num(str[i + 1]) == 0)
            nb_words++;
    }
    return (nb_words);
}

char **my_str_to_word_array(char const *str)
{
    char **word_array = malloc(sizeof(char *) * (count_words(str) + 1));
    int nb_words = 0;
    int i_array = 0;

    if (word_array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i]) == 1)
            nb_words++;
        if (alpha_num(str[i]) == 1 && alpha_num(str[i + 1]) == 0) {
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