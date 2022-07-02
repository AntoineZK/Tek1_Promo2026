/*
** EPITECH PROJECT, 2022
** new_ls [WSL : Ubuntu-20.04]
** File description:
** use_flag
*/

#include "general.h"

char *format_date(char *time)
{
    char *str = malloc(sizeof(char) * 13);
    int j = 0;

    for (int i = 4; i < 16; i++, j++)
        str[j] = time[i];
    str[j] = '\0';
    return (str);
}

void print_ls_l(general_t *g, struct stat lflag, struct dirent *file)
{
    char *tmp = NULL;
    char *date = NULL;

    tmp = my_strdup(g->list->data);
    my_strcat(&tmp, "/");
    my_strcat(&tmp, file->d_name);
    stat(tmp, &lflag);
    perm(lflag.st_mode);
    date = format_date(ctime(&lflag.st_mtime));
    my_printf("%d %s %s %d %s ", lflag.st_nlink,
    getpwuid(lflag.st_uid)->pw_name, getgrgid(lflag.st_gid)->gr_name,
    lflag.st_size, date);
    free(date);
    free(tmp);
}

void get_total(general_t *g)
{
    struct stat lflag;
    char *temp = NULL;
    int total = 0;
    DIR *directory = opendir(g->list->data);
    struct dirent *file = readdir(directory);

    for (; file != NULL; file = readdir(directory)) {
        if (file->d_name[0] == '.' && g->activated_flag[A] == 0)
            continue;
        temp = my_strdup(g->list->data);
        my_strcat(&temp, "/");
        my_strcat(&temp, file->d_name); 
        if (lstat(temp, &lflag) == 0)
            total += lflag.st_blocks;
        free(temp);
    }
    closedir(directory);
    my_printf("total %d\n", total / 2);
}

int ls_loop(general_t *g, DIR *dir, struct dirent *file)
{
    struct stat lflag;

    if (g->activated_flag[L])
        get_total(g);
    file = readdir(dir);
    for (; file; file = readdir(dir)) {
        if (file->d_name[0] == '.' && g->activated_flag[A] == 0)
            continue;
        if (g->activated_flag[L])
            print_ls_l(g, lflag, file);
        print_color(file);
    }
    return (0);
}

int use_flag(general_t *g)
{
    DIR *dir = NULL;
    struct dirent *file = NULL;
    int len = len_list(g->list);
    lk_list *tmp = g->list;

    for (; g->list != NULL; g->list = g->list->next) {
        dir = opendir(g->list->data);
        if (dir == NULL) {
            my_printf("%s: No such file or directory.\n", g->list->data);
            continue;
        }
        if (len > 1)
            my_printf("%s:\n", g->list->data);
        ls_loop(g, dir, file);
        closedir(dir);
    }
    g->list = tmp;
    return (0);
}