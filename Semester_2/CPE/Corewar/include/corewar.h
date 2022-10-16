/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** corewar
*/

#pragma once

#include "my.h"
#include "printf.h"
#include "op.h"

typedef struct func_size_s {
    char arg[4];
} func_size_t;

typedef struct instruction_s {
    char rid;
    int value;
} instruction_t;

typedef struct champions_s {
    char *name;
    char *comment;
    u_char *code;
    int prog_size;
    int number;
    int load_adress;
    int carry;
    int head;
    int alive;
    int tail;
    FILE *ptr;
    int cycles;
    int cycle_to_die;
    int instruction;
    instruction_t instru[4];
    int registre[REG_NUMBER];
    struct champions_s *next;
} champions_t;

typedef struct args_s {
    char *name;
    int number;
    int load_adress;
    struct args_s *next;
} args_t;

typedef struct vm_header_s {
    int magic;
    char *name;
    int prog_size;
    char *comment;
    u_char *code;
}vm_header_t;

typedef struct corewar_s {
    vm_header_t *header;
    int nb_cycle;
    int nb_player;
    int tmp_nb_player;
    int load_adress;
    args_t *list;
    u_char *vm;
    char *last_name;
    int last_number;
    int cycle_to_die;
    int cycle_delta;
    int nb_live;
    champions_t *champ;
}corewar_t;

typedef struct FUNC_PTN
{
    void(*ptr_fct)(corewar_t *, champions_t *);
} func_ptn_t;

corewar_t *init_struct(corewar_t *g);
int hexa_to_decimal(char *hexa);
void find_header(corewar_t *g, char *file);
void get_first_function(char *file);
int decimal_to_binary(int decimal);
int get_arg_alone(int function, FILE *ptr);
func_size_t *get_func_arg(int bitmask);
int get_arg(func_size_t *func_arg, int function, FILE *ptr);
int arg_n(corewar_t *g, char **av, int i);
int arg_a(corewar_t *g, char **av, int i);
int hexa_to_decimal2(int hexa);
int arg_handler(corewar_t *g, int ac, char **av);
int arg_list_handler(corewar_t *g, char **av, int i);
void print_list(args_t *list);
void add_champ(champions_t **list, vm_header_t *header, args_t *arg);
void free_header(vm_header_t *header);
void print_champ(champions_t *champ);
void free_champ(champions_t *champ);
void free_arg(args_t *arg);
void free_all(corewar_t *g);
void place_champion(corewar_t *g);
void write_char_in_mem(corewar_t *g, champions_t *champ, u_char *value,
int size);
int find_function(int mnemonic);
u_char read_char_in_mem(corewar_t *g, champions_t *champ);
void execute_champion(corewar_t *g);
int get_argument(func_size_t *func_arg, int function,
champions_t *champ, corewar_t *g);
int read_ind_in_mem(corewar_t *g, champions_t *champ);
int read_dir_in_mem(corewar_t *g, champions_t *champ);
void execute_live(corewar_t *g, champions_t *champ);
void execute_ld(corewar_t *g, champions_t *champ);
void execute_st(corewar_t *g, champions_t *champ);
void execute_add(corewar_t *g, champions_t *champ);
void execute_sub(corewar_t *g, champions_t *champ);
void execute_and(corewar_t *g, champions_t *champ);
void execute_or(corewar_t *g, champions_t *champ);
void execute_xor(corewar_t *g, champions_t *champ);
void execute_zjmp(corewar_t *g, champions_t *champ);
void execute_ldi(corewar_t *g, champions_t *champ);
void execute_sti(corewar_t *g, champions_t *champ);
void execute_fork(corewar_t *g, champions_t *champ);
void execute_lld(corewar_t *g, champions_t *champ);
void execute_lldi(corewar_t *g, champions_t *champ);
void execute_lfork(corewar_t *g, champions_t *champ);
void execute_aff(corewar_t *g, champions_t *champ);
args_t *add_argument(args_t *list, char *name, int address, int nb_player);
void execute_function(champions_t *champ, corewar_t *g);
void advance_to_next_func(champions_t *champ, corewar_t *g);
args_t *add_node(args_t *list, char *name, int nb_player, int address);
void fork_champ(champions_t *champ);
void print_hexa(int value);
int decimal_to_hexa(int decimal);
