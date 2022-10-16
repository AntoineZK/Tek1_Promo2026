/*
** EPITECH PROJECT, 2022
** need4stek
** File description:
** main
*/

#include "my.h"

static char **lidar(char *str, size_t size, char **tab)
{
    printf("GET_INFO_LIDAR\n");
    getline(&str, &size, stdin);
    if (is_end(str) == 1)
        return (NULL);
    str = clean_lidar(str);
    tab = my_stwa(str);
    return (tab);
}

static int check_status_two(int status)
{
    if (status == 4)
        if (launch("CAR_FORWARD:0.1\n"))
            return (0);
    if (status == 5)
        if (launch("CAR_FORWARD:0.05\n"))
            return (0);
    if (status == 6)
        if (launch("CAR_FORWARD:1\n"))
            return (0);
    return (1);
}

static int check_status(int status)
{
    if (status == 0)
        if (launch("CAR_FORWARD:0.7\n"))
            return (0);
    if (status == 1)
        if (launch("CAR_FORWARD:0.6\n"))
            return (0);
    if (status == 2)
        if (launch("CAR_FORWARD:0.5\n"))
            return (0);
    if (status == 3)
        if (launch("CAR_FORWARD:0.3\n"))
            return (0);
    return (check_status_two(status));
}

int main(void)
{
    char **tab = NULL;
    char *str = NULL;
    size_t size = 0;
    n4s_t *g = malloc(sizeof(n4s_t));

    g = memset(g, 0, sizeof(n4s_t));
    setbuf(stdout, NULL);
    launch("START_SIMULATION\n");
    while (1) {
        if (!check_status(g->status))
            break;
        tab = lidar(str, size, tab);
        if (tab == NULL)
            return (0);
        if (algorithm(tab, g))
            break;
        size = 0;
    }
    return (0);
}
