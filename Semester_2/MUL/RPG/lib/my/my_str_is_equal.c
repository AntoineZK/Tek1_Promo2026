/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_str_is_equal
*/

#include "my.h"

int my_str_is_equal(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    for (int i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}
