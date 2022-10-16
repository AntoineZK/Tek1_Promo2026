/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** map_manager
*/

#include "../include/defender.h"

image_t *map_object(char const *map, sfVector2f pos, int i)
{
    if (map[i] == '0')
        return (image_create("res/grass.png", pos));
    return (image_create("res/sand.png", pos));
}

map_t *add_map_t(char const *map, sfVector2f pos, int i)
{
    map_t *element = malloc(sizeof(map_t));
    element->value = map_object(map, pos, i);
    element->next = NULL;
    return (element);
}

map_t *load_map(const char *map)
{
    int x = 0;
    int y = 0;
    map_t *list = NULL;
    list = add_map_t(map,(sfVector2f) {x, y}, 0);
    x += sfTexture_getSize(list->value->texture).x;
    map_t *backup = list;
    for (int i = 1; map[i]; i++) {
        if (map[i] == '\n') {
            y += 108;
            x = 0;
        } else {
            list->next = add_map_t(map,(sfVector2f) {x, y}, i);
            x += sfTexture_getSize(list->value->texture).x;
            list = list->next;
        }
    }
    list = backup;
    return (list);
}

map_t *print_map(defender_t *defender, map_t *map)
{
    map_t *old_map = map;
    while (map) {
        sfRenderWindow_drawSprite(defender->wdw, map->value->sprite, NULL);
        map = map->next;
    }
    map = old_map;
    return (map);
}

char *get_map(char *filepath)
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
    return (buffer);
}
