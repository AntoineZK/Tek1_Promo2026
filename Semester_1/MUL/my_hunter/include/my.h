/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <math.h>

#endif

int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_put_nbr(int number);
int my_int_len(int number);
char *int_to_char(int nb);
