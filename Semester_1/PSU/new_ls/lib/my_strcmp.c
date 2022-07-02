/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1 , char const *s2)
{
    int len_word1 = my_strlen(s1);
    int len_word2 = my_strlen(s2);

    if (len_word1 != len_word2)
        return (0);
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (0);
    }
    return (1);
}
