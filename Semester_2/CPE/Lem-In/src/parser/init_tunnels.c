/*
** EPITECH PROJECT, 2022
** B-CPE-200-NCY-2-1-lemin-antoine.khalidy
** File description:
** init_tunnels
*/

#include "lemin.h"

char *get_first_id(char *str)
{
    char *id = malloc(sizeof(str));
    int i = 0;

    for (; str[i]; i++) {
        id[i] = str[i];
        if (str[i] == '-')
            break;
    }
    if (i <= 0 || i == my_strlen(str))
        return (NULL);
    id[i] = '\0';
    return (id);
}

char *get_secon_id(char *str)
{
    char *id = malloc(sizeof(str));
    int i = 1;
    int j = 0;

    for (; str[i]; i++) {
        if (str[i - 1] == '-')
            break;
    }
    for (; str[i]; j++) {
        id[j] = str[i];
        i++;
    }
    id[j] = 0;
    return (id);
}

tunnels_t *add_link(tunnels_t *tun, rooms_t *g, char *id2)
{
    tunnels_t *tmptun = malloc(sizeof(tunnels_t));
    rooms_t *tmp = g;

    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->id, id2))
            break;
    }
    if (!my_strcmp(tmp->id, id2))
        return (NULL);
    tmptun->dest = tmp;
    tmptun->next = tun;
    tun = tmptun;
    return (tun);
}

int link_atob(lemin_t *g, char *id1, char *id2)
{
    rooms_t *tmp = g->alg;
    tunnels_t *tmp2 = NULL;

    for (; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->id, id1))
            break;
    }
    if (!my_strcmp(tmp->id, id1))
        return (84);
    tmp2 = tmp->tunnel;
    for (; tmp2 != NULL; tmp2 = tmp2->next) {
        if (my_strcmp(tmp2->dest->id, id2))
            return (0);
    }
    tmp->tunnel = add_link(tmp->tunnel, g->alg, id2);
    if (tmp->tunnel == NULL)
        return (84);
    return (0);
}

int init_tunnels(lemin_t *g, int i)
{
    char *id1 = NULL;
    char *id2 = NULL;
    char *tmp = malloc(sizeof(char));

    tmp[0] = '\0';
    for (; g->d_map[i]; i++) {
        my_strcat(&tmp, g->d_map[i]);
        my_strcat(&tmp, "\n");
        id1 = get_first_id(g->d_map[i]);
        id2 = get_secon_id(g->d_map[i]);
        if (!check_room(g, id1) || !check_room(g, id2))
            return (84);
        link_atob(g, id1, id2);
        link_atob(g, id2, id1);
        free(id1);
        free(id2);
    }
    g->tun = my_stwa(tmp, '\n');
    free(tmp);
    return (0);
}
