/*
** EPITECH PROJECT, 2022
** ../include/my.h
** File description:
** ../include/my.h
*/

#ifndef MY_H
    #define MY_H
    #include <fcntl.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
#endif

int my_abs(int nb);
int my_getnbr(char const *str);
int my_int_len(int number);
int count_nb(int nb);
char *int_to_char(int nb);
void my_intcpy(int *dest, char *src);
int my_puterror(char const *str);
int my_putnbr(int number);
int my_putstr(char const *str);
char *my_strncpy(char *dest, const char *src, int n);
char **my_str_to_word_array(char const *str);
void my_strcat(char **dest, char const *src);
int my_strcmp(char const *s1 , char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_strncmp(char const *s1 , char const *s2 , int n);
void free_double_array(char **darray);
int **alloc_dstar_int(int nb_l, int nb_c, int **to_alloc);
void free_dint_array(int **darray, int nb_line);
void *my_memset(void *to_set, int character, size_t n);
char **my_str_to_word_array_bis(char const *str);
char *my_strcomb(char *fstr, char *lstr);
