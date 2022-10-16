/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int len = 0;
    for (; str[len] != '\0'; len++);
    return (len);
}
