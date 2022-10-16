/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** paser
*/

#include "lemin.h"

char *get_ant(void)
{
    char *buffer = malloc(sizeof(char));
    char *line = NULL;
    long unsigned int size = 0;
    ssize_t byte = 0;

    buffer[0] = '\0';
    byte = getline(&line, &size, stdin);
    while (byte >= 0 && line[0] != '\n') {
        my_strcat(&buffer, line);
        byte = getline(&line, &size, stdin);
    }
    free(line);
    if (buffer[0] == '\0')
        return (NULL);
    return (buffer);
}

int my_is_num(char *str, char sep)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != sep)
            return (0);
    return (1);
}

void remove_line(char **str, int j)
{
    int i = 0;
    if (str[j + 1] == NULL) {
        free(str[j]);
        str[j] = NULL;
        return;
    }
    free(str[j]);
    i = j;
    for (; str[i + 1]; i++) {
        str[i] = str[i + 1];
    }
    str[i] = NULL;
}

int remove_comment(char **str, int j)
{
    int i = 0;

    if (str[j][0] == '#') {
        remove_line(str, j);
        return (j - 1);
    }
    for (; str[j][i]; i++) {
        if (str[j][i] == '#')
            break;
    }
    if (i == my_strlen(str[j]))
        return (j);
    if (str[j][i] == ' ')
        i--;
    for (; i >= 0; --i) {
        if (str[j][i] != ' ')
            break;
    }
    my_strncpy(str[j], str[j], i);
    return (j);
}

int parser(lemin_t *g)
{
    int nb_start = 0;
    int nb_end = 0;

    g->c_map = get_ant();
    if (g->c_map == NULL)
        return (84);
    g->d_map = my_stwa(g->c_map, '\n');
    for (int i = 0; g->d_map[i]; i++) {
        my_strcmp(g->d_map[i], "##start") ? nb_start++ : 0;
        my_strcmp(g->d_map[i], "##end") ? nb_end++ : 0;
        if (!my_strcmp(g->d_map[i], "##end") &&
        !my_strcmp(g->d_map[i], "##start")) {
            i = remove_comment(g->d_map, i);
        }
    }
    if (get_data(g) == 84 || nb_start != 1 || nb_end != 1) {
        free_double_array(g->d_map);
        return (84);
    }
    return (0);
}
