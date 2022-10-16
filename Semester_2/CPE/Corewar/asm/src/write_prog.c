/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_prog
*/

#include "../include/asm.h"

static char where_in_list(char *word, asm_list_t *list_ref, asm_list_t *list)
{
    char where = 0;

    word += 2;
    where = zjump_size(list_ref, list, word);
    word -= 2;
    return (where);
}

static void print_reg(char *arg, int core)
{
    char reg = 0;

    arg++;
    reg = my_atoi(arg);
    write(core, &reg, REG_SIZE);
    arg--;
}

static void print_ind(char *arg, int core, asm_list_t *ref, asm_list_t *list)
{
    char ind[IND_SIZE] = {0};
    int where = 0;
    asm_list_t *back = ref;

    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR) {
        where = where_in_list(arg, ref, list);
        *(short*) ind += where;
        ref = back;
    }
    else if (arg[0] == DIRECT_CHAR){
        arg++;
        *(short*)ind = my_atoi(arg);
        arg--;
    } else {
        *(short*) ind = my_atoi(arg);
    }
    *(short*) ind = __builtin_bswap16(*(short*) ind);
    write(core, ind, IND_SIZE);
}

static void print_dir(char *arg, int core, asm_list_t *ref, asm_list_t *list)
{
    int dir = 0;
    int where = 0;
    asm_list_t *back = ref;

    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR) {
        where = where_in_list(arg, ref, list);
        dir += where;
        ref = back;
    } else if (arg[0] == DIRECT_CHAR){
        arg++;
        dir = my_atoi(arg);
        arg--;
    } else {
        dir = my_atoi(arg);
    }
    dir = __builtin_bswap32(dir);
    write(core, &dir, DIR_SIZE);
}

int size_arg(int core, asm_list_t *list, asm_list_t *ref_list)
{
    asm_list_t *back = ref_list;
    char *arg = NULL;

    for (int i = 0; i != list->asm_line.nbr_args; i++) {
        arg = list->tab[list->pos + i + 1];
        if (get_size_elem(arg, list->asm_line.code) == REG_SIZE)
            print_reg(arg, core);
        if (get_size_elem(arg, list->asm_line.code) == IND_SIZE)
            print_ind(arg, core, ref_list, list);
        if (get_size_elem(arg, list->asm_line.code) == DIR_SIZE)
            print_dir(arg, core, ref_list, list);
        ref_list = back;
    }
    return (EXIT_OK);
}
