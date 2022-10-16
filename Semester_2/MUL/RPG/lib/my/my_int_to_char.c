/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_int_to_char
*/

#include "my.h"

static char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char k;

    while (i <= j) {
        k = str[i];
        str[i] = str[j];
        str[j] = k;
        ++i;
        j--;
    }
    return (str);
}

static char * my_strinsert(char const *str, int index, char *value)
{
    int difference = 0;
    int str_len = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (str_len + my_strlen(value) + 1));
    for (int i = 0; i < str_len + my_strlen(value); ++i) {
        if (i >= index && my_strlen(value) + index >= i + 1) {
            new_str[i] = value[i-index];
            difference++;
        } else
            new_str[i] = str[i - difference];
    }
    return (new_str);
}

char *my_int_to_char(int nb)
{
    if (nb == 0)
        return ("0");
    int i = 0;
    int negative = ((nb > 0) ? 0 : 1);
    nb = ((nb > 0) ? nb : nb * -1);
    char *nbr = malloc(sizeof(char) * 11);

    while (nb > 0) {
        nbr[i] = nb % 10 + 48;
        nb = nb/10;
        ++i;
    }
    nbr[i] = '\0';
    my_revstr(nbr);
    return ((negative) ? my_strinsert(nbr, 0, "-") : nbr);
}
