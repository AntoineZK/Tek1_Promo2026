/*
** EPITECH PROJECT, 2022
** B-MUL-100-NCY-1-1-myrunner-antoine.khalidy
** File description:
** map
*/

#include "../include/my.h"
#include "../include/myrunner.h"

linked_list *load_map(char const *map, int x, int y)
{
    linked_list *list = NULL;
    linked_list *element = NULL;
    for (int i = 0; map[i] != '\0'; i++) {
        element = malloc(sizeof(linked_list));
        element = map_object(map, element, (sfVector2f) {x, y}, i);
        if (map[i] == '\n') {
            y += 128;
            x = 0;
            continue;
        }
        element->next = list;
        if (map[i] == ' ') {
            x += 128;
            continue;
        }
        x += sfTexture_getSize(element->value->texture).x;
        list = element;
    }
    return (list);
}

linked_list *map_object(char const *map, linked_list *element, \
sfVector2f pos, int i)
{
    if (map[i] == '1')
        element->value = image_creator("assets/obs_1.png", pos, NULL, DECK);
    if (map[i] == '2')
        element->value = image_creator("assets/obs_2.png", pos, NULL, DECK);
    if (map[i] == '3')
        element->value = image_creator("assets/obs_3.png", pos, NULL, PIKES);
    if (map[i] == '4')
        element->value = image_creator("assets/obs_4.png", pos, NULL, PIKES);
    if (map[i] == '5')
        element->value = image_creator("assets/obs_5.png", pos, NULL, WIN);
    return (element);
}

char *open_map(char const *filename)
{
    char *map = "";
    char *line = NULL;
    size_t line_buffer = 0;
    FILE *file = fopen(filename, "r");
    int line_size = getline(&line, &line_buffer, file);

    while (line_size >= 0) {
        map = my_strcat(map, line);
        line_size = getline(&line, &line_buffer, file);
    }
    free(line);
    fclose(file);
    return (map);
}

int map_value(linked_list *map)
{
    if (map->value->type == PIKES)
        return (1);
    if (map->value->type == WIN)
        return (2);
    return (0);
}
