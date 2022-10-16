/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my
*/

#pragma once
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int my_abs(int nb);
int my_atoi(char const *str);
int my_int_len(int number);
int count_nb(int nb);
char *my_itoa(int nb);
void my_intcpy(int *dest, char *src);
int my_puterror(char const *str);
void my_putnbr_int(int number);
int my_putstr(char const *str);
char *my_strncpy(char *dest, const char *src, int n);
char **my_stwa(char const *str, char del);
void my_strcat(char **dest, char const *src);
int my_strcmp(char const *s1 , char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_strncmp(char const *s1 , char const *s2 , int n);
void free_double_array(char **darray);
int **alloc_dstar_int(int nb_l, int nb_c, int **to_alloc);
void free_dint_array(int **darray, int nb_line);
void *my_memset(void *to_set, int character, size_t len);
char *getline_file(char *filepath);
int write_in_file(char const *filename, char const *data);
char *stat_file(char *filepath);
int my_str_is_num(char *str);
int my_str_is_alpha(char *str);
int my_str_is_alpha_sup(char *str);
int my_str_is_alpha_inf(char *str);
int my_char_is_num(char c);
int my_char_is_alpha(char c);
int my_char_is_alpha_sup(char c);
int my_char_is_alpha_inf(char c);
int my_putchar(char c);
void print_darray(char **darray);
void my_putnbr_float(float value);
void my_printf(char *str, ...);
