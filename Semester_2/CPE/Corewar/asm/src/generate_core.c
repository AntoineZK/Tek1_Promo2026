/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** compile_asm
*/

#include "../include/asm.h"

static int create_core_file(char const *name)
{
    int fd = 0;

    fd = open(name , O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
    S_IRGRP | S_IROTH);
    return (fd);
}

char *clean_buff(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == SEPARATOR_CHAR || buff[i] == '\t')
            buff[i] = ' ';
    return (buff);
}

int generate_core(FILE *asm_fd, char const *name)
{
    int core_fd = create_core_file(name);
    int ret_stat = EXIT_OK;
    char *asm_buff = NULL;

    if (core_fd == -1)
        return (EXIT_ERR);
    asm_buff = getline_file(asm_fd);
    if (asm_buff == NULL) {
        close(core_fd);
        return (EXIT_ERR);
    }
    ret_stat = compile_asm(asm_buff, core_fd);
    free(asm_buff);
    close(core_fd);
    return (ret_stat);
}
