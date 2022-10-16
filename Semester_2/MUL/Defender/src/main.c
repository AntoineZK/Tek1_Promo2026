/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/defender.h"

int defender(map_t *game, char *map)
{
    defender_t *def = malloc(sizeof(defender_t));
    if (def == NULL)
        return (my_put_error("Malloc Problem"));
    init_struct(def, map);
    init_all(def);
    while (sfRenderWindow_isOpen(def->wdw) && def->end == 0) {
        sfMusic_setVolume(def->music, def->volume);
        def->time = sfClock_getElapsedTime(def->clock);
        time_action(def);
        while (sfRenderWindow_pollEvent(def->wdw, &def->event))
            defender_event(def);
        scene_handler(def, game);
    }
    if (def->end == 2)
        write(1, "You Loose\n", 10);
    if (def->end == 1)
        write(1, "You Win\n", 8);
    highscore_set(def);
    destroy_all(def);
    return (0);
}

int main(int argc, char **argv)
{
    char *map;
    map_t *list_map = NULL;
    if (argc > 2)
        return (description_84());
    else if (argc == 2 && my_strcmp(argv[1], "-h"))
        return (description_0());
    map = get_map("maps/map.txt");
    if (map == NULL)
        return (84);
    list_map = load_map(map);
    defender(list_map, map);
    free_element_map(list_map);
    return (0);
}
