/*
** EPITECH PROJECT, 2022
** need4stek
** File description:
** algo
*/

#include "my.h"

static int choose_dir(float direction, char *cmd)
{
    size_t size = 0;

    direction < 0.0 ? printf("WHEELS_DIR:-") : printf("WHEELS_DIR:");
    printf("%s", cmd);
    getline(&cmd, &size, stdin);
    return (is_end(cmd));
}

static int algo_two(float dir, float middle_val, n4s_t *g)
{
    if (middle_val >= 400) {
        g->status = 3;
        return (choose_dir(dir, "0.2\n"));
    }
    if (middle_val >= 200) {
        g->status = 4;
        return (choose_dir(dir, "0.3\n"));
    } else {
        g->status = 5;
        return (choose_dir(dir, "0.5\n"));
    }
}

int algorithm(char **tab, n4s_t *g)
{
    float dir = atof(tab[1]) - atof(tab[31]);
    float middle_val = atof(tab[15]);

    if (middle_val >= 2000) {
        g->status = 6;
        return (choose_dir(dir, "0.0\n"));
    }
    if (middle_val >= 1500) {
        g->status = 0;
        return (choose_dir(dir, "0.005\n"));
    }
    if (middle_val >= 1000) {
        g->status = 1;
        return (choose_dir(dir, "0.05\n"));
    }
    if (middle_val >= 600) {
        g->status = 2;
        return (choose_dir(dir, "0.1\n"));
    }
    return (algo_two(dir, middle_val, g));
}

int launch(char *cmd)
{
    size_t size = 0;

    printf("%s", cmd);
    getline(&cmd, &size, stdin);
    if (is_end(cmd))
        return (1);
    return (is_end(cmd));
}
