/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-myrpg-antoine.khalidy
** File description:
** save
*/

#include "rpg.h"

void get_save(char *save)
{
    char **save_darray = my_stwa(save, ' ');

    rpg->player->pos.x = 0;
    rpg->player->pos.x = my_getnbr(save_darray[0]) * 128;
    rpg->player->pos.y = 0;
    rpg->player->pos.y = my_getnbr(save_darray[1]) * 128;
    rpg->player->life = 0;
    rpg->player->life = my_getnbr(save_darray[2]);
    array_destroy(save_darray);
}

static float set_save_two(float true_value)
{
    true_value /= 128;
    if (true_value < 0)
        true_value = 0;
    return (true_value);
}

int set_save(char *save_file)
{
    char *x_value = my_itoa(set_save_two(rpg->player->pos.x));
    char *y_value = my_itoa(set_save_two(rpg->player->pos.y));
    char *life = my_itoa(rpg->player->life);
    char *save = malloc(sizeof(char));

    save[0] = '\0';
    my_strcat_dyn(&save, x_value);
    my_strcat_dyn(&save, " ");
    my_strcat_dyn(&save, y_value);
    my_strcat_dyn(&save, " ");
    my_strcat_dyn(&save, life);
    my_write_file(save_file, save);
    free(x_value);
    free(y_value);
    free(life);
    free(save);
    return (0);
}
