/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** get_function
*/

#include "../include/corewar.h"

int find_function(int mnemonic)
{
    int i = 0;

    for (; i < 16; i++) {
        if (op_tab[i].code == mnemonic)
            return (i);
    }
    return (-1);
}

int get_function(FILE *ptr)
{
    int mnemonic = 0;
    int function = 0;

    fread(&mnemonic, 1, 1, ptr);
    function = find_function(mnemonic);
    if (function == -1) {
        return (-1);
    }
    return (function);
}

int get_arg_alone(int function, FILE *ptr)
{
    int argument = 0;
    int arg = 0;
    int dir_size = 2;

    if (function == 0)
        dir_size = DIR_SIZE;
    if (op_tab[function].type[0] == T_DIR)
        arg = dir_size;
    if (op_tab[function].type[0] == T_REG)
        arg = 1;
    if (op_tab[function].type[0] == T_IND)
        arg = IND_SIZE;
    fread(&argument, 1, arg, ptr);
    argument = __builtin_bswap32(argument);
    return (arg);
}

int get_all_function(FILE *ptr)
{
    int function = 0;
    int bitmask = 0;
    func_size_t *func_size = NULL;

    function = get_function(ptr);
    if (function == -1 )
        return (-1);
    if (op_tab[function].nbr_args != 1 || op_tab[function].code == 16)
        fread(&bitmask, 1, 1, ptr);
    else
        bitmask = 0;
    func_size = get_func_arg(bitmask);
    get_arg(func_size, function, ptr);
    free(func_size);
    return (0);
}

void get_first_function(char *file)
{
    FILE *ptr = fopen(file, "rb");
    int pos = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;

    fseek(ptr, pos, SEEK_SET);
    while (get_all_function(ptr) != -1);
    fclose(ptr);
}
