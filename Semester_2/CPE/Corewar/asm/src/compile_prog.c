/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_name
*/

#include "../include/asm.h"

static char *remove_comment(char *line, int pos, int comment)
{
    int size_line = my_strlen(line);

    if (comment != 0)
        for (int i = 0; i != size_line; i++, pos++)
            line[pos] = '\0';
    return (line);
}

static asm_list_t *check_asm_line(char *line, asm_list_t *list)
{
    int size_comment = my_strlen(COMMENT_CMD_STRING);
    int size_name = my_strlen(NAME_CMD_STRING);
    int comment = -1;

    for (int comment_pos = 0; line[comment_pos] != '\0'; comment_pos++)
        if (line[comment_pos] == COMMENT_CHAR)
            line = remove_comment(line, comment_pos, comment);
    if (my_strncmp(COMMENT_CMD_STRING, line, size_comment)||
        my_strncmp(NAME_CMD_STRING, line, size_name))
        return (0);
    list = add_nod_list(list, line);
    if (list == NULL) {
        return (NULL);
    }
    return (list);
}

static header_t *init_header(void)
{
    header_t *header = malloc(sizeof(header_t));
    header = my_memset(header, 0, sizeof(header_t));

    if (header == NULL)
        return (NULL);
    header->magic = 0;
    header->prog_size = 0;

    return (header);
}

int compile_asm(char *asm_buff, int core_fd)
{
    core_fd = core_fd;
    int ret_stat = EXIT_OK;
    header_t *header = init_header();
    asm_list_t *list = NULL;

    if (header == NULL)
        return (EXIT_ERR);
    header = generate_header(header, asm_buff);
    if (header == NULL)
        return (EXIT_ERR);
    asm_buff = clean_buff(asm_buff);
    list = compile_core(list, asm_buff);
    if (list != NULL) {
        pars_code_list(list);
        ret_stat = check_list_elem(list);
    }
    write_core(core_fd, header, list);
    return (ret_stat);
}

asm_list_t *compile_core(asm_list_t *list, char *asm_buff)
{
    char **tab = my_spliter(asm_buff, '\n');

    for (int i = 0; tab[i] != NULL; i++)
        list = check_asm_line(tab[i], list);
    free_double_array(tab);
    return (list);
}
