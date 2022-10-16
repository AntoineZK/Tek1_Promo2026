/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCY-2-1-mydefender-antoine.khalidy
** File description:
** score
*/

#include "../include/defender.h"

int highscore_get(defender_t *def)
{
    FILE *file_d = fopen("score/max_wave", "a+");
    char *buffer = NULL;
    size_t size_buffer = 0;
    if (file_d == NULL)
        return (-1);
    while (getline(&buffer, &size_buffer, file_d) != -1);
    buffer != NULL ? def->mwave = my_getnbr(buffer) : 0;
    free(buffer);
    fclose(file_d);
    return (0);
}

int highscore_set(defender_t *def)
{
    char *tmp = NULL;
    def->wave > def->mwave ? def->mwave = def->wave : 0;
    int file_d = open("score/max_wave", O_TRUNC | O_WRONLY);
    if (file_d == -1)
        return (-1);
    tmp = int_to_char(def->mwave);
    write(file_d, tmp, my_int_len(def->mwave) - 1);
    free(tmp);
    close(file_d);
    return (0);
}
