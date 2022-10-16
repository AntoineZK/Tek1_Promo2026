/*
** EPITECH PROJECT, 2022
** B-PSU-101-NCY-1-1-minishell1-enzo.valentin
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <string.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>

typedef struct linked_list {
    char *data;
    struct linked_list *next;
} linked_list;

char *my_open_file(char const *filename);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
void my_strcat_dyn(char **dest, char const *src);
int my_str_is_equal(char const *s1, char const *s2);
char **my_str_to_wordarray(char const *str, char delimiter);
int my_getnbr(char const *str);
char **my_arraycpy(char const **array);
int linked_list_len(linked_list *list);
void linked_list_add(linked_list *list, char *data);
void linked_list_remove(linked_list *list, char *data);
char **linked_list_to_array(linked_list *list);
linked_list *array_to_linked_list(char **array);
int is_alpha(char **content);
int my_char_is_alpha(char c);
char *my_itoa(int nb);
int my_hexa_to_int(char const *str);
int my_write_file(char const *filename, char const *data);
void *my_memset(void *to_set, int character, size_t n);
char **my_stwa(char const *str, char del);
char *my_int_to_char(int nb);
char *my_strcpy(char const *src);
void array_destroy(char **array);
int my_putstr(char const *str);
void my_strcpy_dyn(char **dest, char const *src);
char *my_ftoa(float nb);
int my_puterror(char const *str);

#endif/* !MY_H_ */
