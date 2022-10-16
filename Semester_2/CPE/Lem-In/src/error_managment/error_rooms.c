/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** error_rooms
*/

#include "lemin.h"

int check_nbr(char *str)
{
    char *tmp = str;
    int i = 0;
    for (; tmp[i] != ' '; i++);
    tmp += i;
    if (my_is_num(tmp, ' ') == 0)
        return (1);
    return (0);
}

int error_rooms(char **str)
{
    if (str[1] == NULL)
        return (1);
    for (int i = 1; str[i]; i++) {
        if (str[i][0] == '#')
            continue;
        if (check_nbr_arg(str[i], '-') == 2)
            break;
        if (check_nbr_arg(str[i], ' ') != 3)
            return (1);
        if (check_nbr(str[i]) == 1)
            return (1);
    }
    return (0);
}

int check_room(lemin_t *g, char *id)
{
    rooms_t *tmp = g->alg;

    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->id, id))
            return (1);
    }
    return (0);
}

int check_start_end(lemin_t *g, type_t type)
{
    rooms_t *tmp = g->alg;
    int check = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == type)
            check++;
    }
    if (check != 1)
        return (0);
    return (1);
}

int check_repeat_name(lemin_t *g)
{
    rooms_t *tmp = g->alg;
    int check = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        for (rooms_t *tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next) {
            check += my_strcmp(tmp->id, tmp2->id);
        }
    }
    return (check);
}
