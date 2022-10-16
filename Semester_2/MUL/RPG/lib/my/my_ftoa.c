/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_ftoa
*/

#include "my.h"

int my_int_len(int number)
{
    int nb_div = 1;
    int result = 1;

    if (number == 0)
        number = 1;
    for (; number / nb_div >= 1; result++)
        nb_div = nb_div * 10;
    return (result);
}

char *my_ftoa(float nb)
{
    char *str = malloc(sizeof(char) * 1000);
    int i = 0;
    int int_part = (int) nb;
    float dec_part = nb - int_part;
    char *tmp_int = my_int_to_char(int_part);

    str[i] = '\0';
    my_strcat_dyn(&str, tmp_int);
    my_strcat_dyn(&str, ".");
    i = my_int_len(int_part);
    for (int j = 0; j < 2; j++) {
        dec_part *= 10;
        str[i] = '0' + (int) dec_part;
        ++i;
        dec_part -= (int) dec_part;
    }
    str[i] = '\0';
    return (str);
}
