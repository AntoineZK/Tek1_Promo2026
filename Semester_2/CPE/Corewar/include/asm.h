/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** asm
*/

#ifndef _ASM_H
    #define _ASM_H
    #include "my.h"
    #include "op.h"
    #include "printf.h"
    #include <inttypes.h>
    #include <stdio.h>
    #define EXIT_ERR 84
    #define EXIT_OK 0

typedef struct asm_list_s {
    char *line;
    int size;
    op_t asm_line;
    int pos;
    char bitmask;
    int good;
    char **tab;
    struct asm_list_s *next;
} asm_list_t;

int generate_core(FILE *file, char const *name);
asm_list_t *compile_core(asm_list_t *list, char *asm_buff);
int compile_asm(char *asm_buff, int core_fd);
int magic_header(int *header);
int name_header(char **asm_buff, char *name);
int comment_header(char **asm_buff, char *comment);
header_t *generate_header(header_t *header, char *asm_buff);
char *find_line(char **tab, char *search);
int write_core(int core, header_t *header, asm_list_t *list);
int write_prog(int core, asm_list_t *list);
asm_list_t *add_nod_list(asm_list_t *list, char *line);
int search_list_char(asm_list_t *list, char *word);
void free_linked_list(asm_list_t *list);
int pars_code_list(asm_list_t *list);
int check_list_elem(asm_list_t *list);
int check_type(char *word);
int get_size_elem(char *word, int type);
char *clean_buff(char *buff);
int get_size_prog(asm_list_t *list);
void get_bytemask(asm_list_t *list, int core);
int size_arg(int core, asm_list_t *list, asm_list_t *ref_list);
int zjump_size(asm_list_t *list, asm_list_t *zjump, char *word);

#endif
