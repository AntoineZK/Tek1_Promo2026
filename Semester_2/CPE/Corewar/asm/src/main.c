/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "../include/asm.h"

static int helper(char *prog, int ret_val)
{
    my_printf("USAGE:\n%s [-h] filename.[s]\n", prog);
    my_printf("DESCRIPTION:\nCompile filename.s to ");
    my_printf("filename.cor for corewar Virtual Machine\n");
    return (ret_val);
}

static int check_arg (int ac, char **argv)
{
    if (ac > 2 || ac == 1)
        return (helper(argv[0], EXIT_ERR));
    if (my_strncmp(argv[1], "-h", my_strlen("-h")))
        helper(argv[0], EXIT_OK);
    return (EXIT_OK);
}

static FILE *open_file(char const *filepath)
{
    FILE *file = 0;

    file = fopen(filepath, "r");
    if (file == NULL) {
        my_printf("Error while opening file %s\n", filepath);
        return (NULL);
    }
    return (file);
}

static char *get_filename(char const *path)
{
    int size = my_strlen(path) + my_strlen(".cor\0") + 1;
    char *name = malloc(sizeof(char) * size);

    if (name == NULL)
        return (NULL);
    if (path == NULL) {
        free(name);
        return (NULL);
    }
    name = my_memset(name, 0, size);
    name = my_strcpy(name, path);
    for (int i = 0; name[i] != '\0'; i++)
        if (name[i + 1] != '\0' && name[i] == '.') {
            name[i + 1] = '.';
            name[i] = '\0';
        }
    name = my_strcat(name, ".cor");

    return (name);
}

int main (int ac, char **argv)
{
    int ret_stat = EXIT_OK;
    FILE *file = NULL;
    char *name = NULL;

    if (check_arg(ac, argv) != EXIT_OK)
        return (EXIT_ERR);
    name = get_filename(argv[1]);
    if (name == NULL)
        return (EXIT_ERR);
    file = open_file(argv[1]);
    if (file == NULL) {
        free(name);
        return (EXIT_ERR);
    }
    ret_stat = generate_core(file, name);
    free(name);
    fclose(file);
    return (ret_stat);
}
