/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** get_header
*/

#include "../include/corewar.h"

void find_header(corewar_t *g, char *file)
{
    int comment_pos = PROG_NAME_LENGTH + 8;
    FILE *ptr = fopen(file, "rb");

    fread(&g->header->magic, 4, 1, ptr);
    g->header->magic = __builtin_bswap32(g->header->magic);
    fread(g->header->name, PROG_NAME_LENGTH, 1, ptr);
    fseek(ptr, comment_pos, SEEK_SET);
    fread(&g->header->prog_size, 4, 1, ptr);
    g->header->prog_size = __builtin_bswap32(g->header->prog_size);
    fread(g->header->comment, COMMENT_LENGTH, 1, ptr);
    if (g->header->code != NULL)
        free(g->header->code);
    g->header->code = malloc(sizeof(char) * (g->header->prog_size +2));
    g->header->code == NULL ? exit(84) : 0;
    fseek(ptr, 4, SEEK_CUR);
    fread(g->header->code, g->header->prog_size, 1, ptr);
    g->header->code[g->header->prog_size + 1] = '\0';
    fclose(ptr);
}

void free_header(vm_header_t *header)
{
    free(header->name);
    free(header->comment);
    free(header->code);
    free(header);
}
