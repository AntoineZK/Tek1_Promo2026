/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** wave_manager.c
*/

#include "../include/defender.h"

char **my_stwa(char *str, char lim, char end)
{
    int nb_word = 1;
    int size = 0;
    int co = 0;
    char **tab;
    int j = 0;
    for (int i = 0; str[i] != end; i++)
        if (str[i] == lim)
            nb_word++;
    tab = malloc(sizeof(char*) * (nb_word + 1));
    tab[nb_word] = NULL;
    for (int i = 0; i != nb_word; i++) {
        for (size = 0; str[size + co] != lim && str[size + co] != end; size++);
        tab[i] = malloc(sizeof(char) * (size + 1));
        for (j = 0; j != size; j++)
            tab[i][j] = str[j + co];
        tab[i][j] = '\0';
        co += (size + 1);
    }
    return (tab);
}

char **get_txt_file(char *filepath)
{
    char *buffer = "";
    char *line = NULL;
    long unsigned int size = 0;
    ssize_t byte = 0;
    FILE *file = fopen(filepath, "r");
    if (!file)
        return (NULL);
    while ((byte = getline(&line, &size, file)) >= 0)
        buffer = my_strcat(buffer, line);
    fclose(file);
    free(line);
    char **tab = my_stwa(buffer, '\n', '\0');
    free(buffer);
    return (tab);
}

mob_t *nod_creator(char **wave_data, sfVector2f pos, sfTexture *texture)
{
    mob_t *nod = malloc(sizeof(mob_t));
    nod->sprite = sfSprite_create();
    sfSprite_setTexture(nod->sprite, texture, sfTrue);
    nod->life = my_getnbr(wave_data[3]);
    nod->speed = my_getnbr(wave_data[4]);
    nod->speed_max = my_getnbr(wave_data[4]);
    nod->armor = my_getnbr(wave_data[5]);
    nod->checkp = 0;
    nod->size.y = my_getnbr(wave_data[6]) / 2;
    nod->size.x = my_getnbr(wave_data[7]) / 2;
    nod->clock_monster = sfClock_create();
    sfSprite_setTextureRect(nod->sprite, (sfIntRect) {0, 0, 108, 108});
    nod->pos = pos;
    return (nod);
}

mob_t *wave_creator(defender_t *g, sfVector2f pos)
{
    char ** wave_data = my_stwa(g->wave_list[g->wave], ' ', '\0');
    g->mob_text = sfTexture_createFromFile(wave_data[1], NULL);
    mob_t *wave = nod_creator(wave_data, pos, g->mob_text);
    mob_t *backup = wave;
    for (int i = 0; i != my_getnbr(wave_data[2]); i++) {
        wave->next = nod_creator(wave_data, pos, g->mob_text);
        wave = wave->next;
        wave->pos.y -= my_getnbr(wave_data[6]) * (i + 1);
    }
    wave->next = NULL;
    wave = backup;
    free_double_array(wave_data);
    return (wave);
}
