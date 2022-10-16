/*
** EPITECH PROJECT, 2022
** my_stwa
** File description:
** my_stwa
*/

#include "my.h"

static int len_of_word(char const *str, int index, char delimiter)
{
    int len = 0;
    for (; str[index + len] != delimiter && str[index + len] != '\0'; len++);
    return (len);
}

static int nb_of_words(char const *str, char delimiter)
{
    int words = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] == delimiter)
            i++;
        if (str[i] == '\0')
            break;
        words++;
        while (str[i] != delimiter && str[i] != '\0')
            i++;
        i--;
    }
    return (words);
}

char **my_stwa(char const *str, char delimiter)
{
    int words = nb_of_words(str, delimiter);
    char **array = malloc(sizeof(char *) * (words + 1));
    int index = 0;
    for (int i = 0; i < words; i++) {
        for (; str[index] == delimiter; index++);
        int size = len_of_word(str, index, delimiter);
        array[i] = malloc(sizeof(char) * (size + 1));
        for (int j = 0; str[index + j] != delimiter &&
        str[index + j] != '\0'; j++)
            array[i][j] = str[index + j];
        index += size;
        array[i][size] = '\0';
        for (; str[index] == delimiter; index++);
    }
    array[words] = NULL;
    return (array);
}

void free_double_array(char **darray)
{
    for (int i = 0; darray[i]; i++)
        free(darray[i]);
    free(darray);
}
