/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-antoine.khalidy
** File description:
** my
*/

#ifndef MY_H
    #define MY_H

    #include <fcntl.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <libgen.h>
    #include <sys/shm.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>

#endif
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_put_nbr(int number);
char *my_strncpy(char *dest, const char *src, int n);
char **my_str_to_word_array(char const *str);
int len_of_word(char const *str, int start);
int count_words(char const *str);
int alpha_num(char character);
int my_strcmp(char const *s1 , char const *s2);
int my_puterror(char const *str);
int my_strncmp(char const *s1 , char const *s2 , int n);
int my_str_contain(char *str);
