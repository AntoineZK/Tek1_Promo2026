/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCY-2-1-tetris-antoine.khalidy
** File description:
** parser
*/

#include "../include/tetris.h"

int countchar(char *s, char c)
{
    int k = 0;
    for (int i = 0; s[i]; i++) {
        if ((s[i] == c && s[i - 1] != c) || (s[i] == '\t' && s[i - 1] != '\t'))
            k++;
    }
    return (k);
}

int check_space(char *buf, int i)
{
    if (buf[i] == ' ' || buf[i] == '\t')
        if (buf[i + 1] == ' ' || buf[i + 1] == '\t')
            return (1);
    return (0);
}

char *remove_tab(char *buf)
{
    for (int i = 0; buf[i]; i++) {
        if (buf[i] == '\t')
            buf[i] = ' ';
    }
    for (int i = my_strlen(buf); buf[i] == ' '; i--) {
        buf[i] = buf[i - 1];
    }
    return (buf);
}

char *remove_space(char *buf)
{
    while (1) {
        if (buf[my_strlen(buf) - 1] == ' ') {
            my_strcpyto(buf, buf, my_strlen(buf) - 2);
            continue;
        }
        break;
    }
    return (buf);
}

char **parse(char *str, char separator)
{
    int i = countchar(str, separator);
    int j = 0;
    int l = 0;
    char **buffer = malloc(sizeof(char) * (my_strlen(str) * i));
    i += countchar(str, 9);
    for (int k = 0; k <= i; k++)
        buffer[k] = malloc(sizeof(char) * (my_strlen(str)));
    buffer[i + 1] = NULL;
    for (int k = 0; str[k]; k++) {
        if (!((str[k] == separator || str[k] == '\t') && l == 0)) {
            buffer[j][l] = str[k];
            l++;
        }
        if ((str[k] == separator || str[k] == '\t') && l > 0) {
            buffer[j][l - 1] = '\0';
            j++;
            l = 0;
        }
    } return (buffer);
}
