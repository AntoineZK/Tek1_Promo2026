/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** my_revstr
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    int len_str = 0;
    char tempo;

    while (str[len_str] != '\0'){
        len_str++;
    }
    len_str--;
    for (int i = 0; i < len_str; i++) {
        tempo = str[len_str];
        str[len_str] = str[i];
        str[i] = tempo;
        len_str--;
    }
    return (str);
}
