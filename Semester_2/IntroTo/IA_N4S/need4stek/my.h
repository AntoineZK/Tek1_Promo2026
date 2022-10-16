/*
** EPITECH PROJECT, 2022
** need4stek
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>

typedef struct n4s_s {
    int status;
} n4s_t;

char **my_stwa(char const *str);
char *clean_lidar(char *str);
int launch(char *str);
int is_end(char *end);
int algorithm(char **tab, n4s_t *g);

#endif
